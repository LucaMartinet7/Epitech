import 'package:http/http.dart' as http;
import 'dart:convert';
import 'package:shared_preferences/shared_preferences.dart';
import '../shared/api_service.dart' show getApiUrl;

class UserProfile {
  final String username;
  final String email;
  final String profileImagePath;

  UserProfile({required this.username, required this.email, required this.profileImagePath});

  factory UserProfile.fromJson(Map<String, dynamic> json) {
    return UserProfile(
      username: json['username'],
      email: json['email'],
      profileImagePath: json['profile_image'] ?? 'assets/images/profile/profile.png',
    );
  }
}

Future<UserProfile> fetchUserProfile(String username) async {
  final response = await http.get(
    Uri.parse(await getApiUrl('api/auth/auth/user-info/$username/')),
  );
  if (response.statusCode == 200) {
    return UserProfile.fromJson(json.decode(response.body));
  } else {
    throw Exception('Failed to load user profile');
  }
}

Future<String?> getUsername() async {
  final prefs = await SharedPreferences.getInstance();
  return prefs.getString('username');
}