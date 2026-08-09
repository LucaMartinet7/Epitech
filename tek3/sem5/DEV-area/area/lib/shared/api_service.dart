import 'package:http/http.dart' as http;
import 'dart:convert';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:shared_preferences/shared_preferences.dart';

Future<http.Response> postRequest({
  required String url,
  required Map<String, String> headers,
  required Map<String, dynamic> body,
}) async {
  final response = await http.post(
    Uri.parse(url),
    headers: headers,
    body: jsonEncode(body),
  );
  return response;
}

Future<String> getApiUrl(String endpoint) async {
  if (kIsWeb) {
    return 'http://127.0.0.1:8000/$endpoint';
  } else {
    return 'http://CUSTOMIP:8000/$endpoint'; //make sur the ip is correct and added to settings.py ALLOWED_HOSTS
  }
}

Future<void> login({
  required BuildContext context,
  required String username,
  required String password,
}) async {
  final response = await postRequest(
    url: await getApiUrl('api/auth/login/'),
    headers: {'Content-Type': 'application/json'},
    body: {
      'username': username,
      'password': password,
    },
  );

  if (!context.mounted) return;

  if (response.statusCode == 200) {
    try {
      await obtainAndSaveToken(username, password);
      if (context.mounted) {
        Navigator.pushReplacementNamed(context, '/dashboard');
      }
    } catch (e) {
      if (context.mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Failed to obtain token: $e')),
        );
      }
    }
  } else {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text('Login failed: ${response.statusCode}')),
    );
  }
}

Future<void> register({
  required BuildContext context,
  required String username,
  required String password,
  required String email,
}) async {
  final response = await postRequest(
    url: await getApiUrl('api/auth/register/'),
    headers: {'Content-Type': 'application/json'},
    body: {
      'username': username,
      'password': password,
      'email': email,
      'first_name': 'none',
      'last_name': 'none',
    },
  );

  if (!context.mounted) return;

  if (response.statusCode == 201) {
    Navigator.pushNamed(context, '/login');
  } else {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(content: Text('Registration failed: ${response.statusCode}')),
    );
  }
}

Future<void> obtainAndSaveToken(String username, String password) async {
  final response = await http.post(
    Uri.parse(await getApiUrl('api/auth/token/')),
    headers: {'Content-Type': 'application/json'},
    body: jsonEncode({'username': username, 'password': password}),
  );

  if (response.statusCode == 200) {
    final data = jsonDecode(response.body);
    final accessToken = data['access'];
    final refreshToken = data['refresh'];

    final prefs = await SharedPreferences.getInstance();
    await prefs.setString('access_token', accessToken);
    await prefs.setString('refresh_token', refreshToken);
    await prefs.setString('username', username); // Store the username
  } else {
    throw Exception('Failed to obtain token');
  }
}

Future<bool> isTokenValid(String refreshToken) async {
  final response = await http.post(
    Uri.parse(await getApiUrl('api/auth/token/refresh/')),
    headers: {
      'Content-Type': 'application/json',
      'accept': 'application/json',
    },
    body: jsonEncode({'refresh': refreshToken}),
  );

  if (response.statusCode == 200) {
    jsonDecode(response.body);
    return true;
  } else {
    return false;
  }
}

Future<void> logout(BuildContext context) async {
  final prefs = await SharedPreferences.getInstance();
  await prefs.remove('access_token');
  await prefs.remove('refresh_token');

  if (context.mounted) {
    Navigator.pushReplacementNamed(context, '/login');
  }
}

Future<List<String>> fetchActions() async {
  final response = await http.get(Uri.parse(await getApiUrl('api/actions/')));

  if (response.statusCode == 200) {
    List<dynamic> data = json.decode(response.body);
    return data.map((action) => action.toString()).toList();
  } else {
    throw Exception('Failed to load actions');
  }
}

Future<List<String>> fetchReactions() async {
  final response = await http.get(Uri.parse(await getApiUrl('api/reactions/')));

  if (response.statusCode == 200) {
    List<dynamic> data = json.decode(response.body);
    return data.map((reaction) => reaction.toString()).toList();
  } else {
    throw Exception('Failed to load reactions');
  }
}

Future<void> launchURL(String url) async {
  final Uri uri = Uri.parse(url);
  if (!await launchUrl(uri, mode: LaunchMode.externalApplication)) {
    throw 'Could not launch $url';
  }
}

Future<bool> isLoggedIn() async {
  final prefs = await SharedPreferences.getInstance();
  final accessToken = prefs.getString('access_token');
  final refreshToken = prefs.getString('refresh_token');
  if (accessToken != null && refreshToken != null) {
    return true;
  }
  return false;
}