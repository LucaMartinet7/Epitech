import 'package:flutter/material.dart';
import 'package:url_launcher/url_launcher.dart';
import '../shared/service_box.dart';
import 'web_nav_bar.dart';
import '../shared/user_service.dart';
import 'package:shared_preferences/shared_preferences.dart';

class Service {
  final String name;
  final String logoPath;
  bool isConnected;
  final String loginUrl;

  Service(this.name, this.logoPath, this.isConnected, this.loginUrl);
}

class WebDashboard extends StatefulWidget {
  const WebDashboard({super.key});

  @override
  WebDashboardState createState() => WebDashboardState();
}

class WebDashboardState extends State<WebDashboard> {
  final List<Service> services = [
    Service('Spotify', 'assets/images/spotify.png', false, 'http://127.0.0.1:8000/api/auth/spotify/login/'),
    Service('Twitch', 'assets/images/twitch.png', false, 'http://127.0.0.1:8000/api/auth/twitch/login/'),
    Service('Google', 'assets/images/google.png', false, 'http://127.0.0.1:8000/api/auth/google/login/'),
    Service('YouTube', 'assets/images/youtube.png', false, 'http://127.0.0.1:8000/api/auth/google/login/'),
    Service('Bluesky', 'assets/images/bluesky.png', false, 'http://localhost:3000/bluesky/login'),
  ];

  @override
  void initState() {
    super.initState();
    _loadServiceConnections();
  }

  Future<void> _loadServiceConnections() async {
    final prefs = await SharedPreferences.getInstance();
    setState(() {
      for (var service in services) {
        service.isConnected = prefs.getBool(service.name) ?? false;
      }
    });
  }

  Future<void> _saveConnectionState(String serviceName, bool isConnected) async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setBool(serviceName, isConnected);
  }

  void handleConnect(String serviceName, String loginUrl) async {
    final service = services.firstWhere((service) => service.name == serviceName);

    if (service.isConnected) {
      setState(() {
        service.isConnected = false;
      });
      await _saveConnectionState(service.name, false);
    } else {
      final Uri loginUri = Uri.parse(loginUrl);
      if (await canLaunchUrl(loginUri)) {
        await launchUrl(loginUri);
        setState(() {
          service.isConnected = true;
        });
        await _saveConnectionState(service.name, true);
      } else {
        throw 'Could not launch $loginUrl';
      }
    }
  }

  void handleDisconnect(String serviceName) async {
    final service = services.firstWhere((service) => service.name == serviceName);
    setState(() {
      service.isConnected = false;
    });
    await _saveConnectionState(service.name, false);
  }

  void resetConnections() async {
    setState(() {
      for (var service in services) {
        service.isConnected = false;
      }
    });
    final prefs = await SharedPreferences.getInstance();
    for (var service in services) {
      await prefs.setBool(service.name, false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: const WebNavBar(),
      body: Center(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: FutureBuilder<String?>(
            future: getUsername(),
            builder: (context, snapshot) {
              if (snapshot.connectionState == ConnectionState.waiting) {
                return const CircularProgressIndicator();
              } else if (snapshot.hasError || !snapshot.hasData) {
                return const Text('Failed to load username');
              } else {
                final username = snapshot.data!;
                return Row(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    _buildProfile(context, username),
                    const SizedBox(width: 16),
                    _buildServiceBoxes(services, handleConnect),
                  ],
                );
              }
            },
          ),
        ),
      ),
    );
  }

  Widget _buildProfile(BuildContext context, String username) {
    return Expanded(
      flex: 1,
      child: Container(
        padding: const EdgeInsets.all(16.0),
        decoration: _boxDecoration(),
        child: FutureBuilder<UserProfile>(
          future: fetchUserProfile(username),
          builder: (context, snapshot) {
            if (snapshot.connectionState == ConnectionState.waiting) {
              return const CircularProgressIndicator();
            } else if (snapshot.hasError) {
              return _buildProfileContent(
                CircleAvatar(
                  radius: 100,
                  child: const Icon(Icons.person, size: 70),
                ),
                'Error',
                'error@example.com',
              );
            } else if (!snapshot.hasData) {
              return _buildProfileContent(
                CircleAvatar(
                  radius: 100,
                  child: const Icon(Icons.person, size: 70),
                ),
                'No Data',
                'nodata@example.com',
              );
            } else {
              final userProfile = snapshot.data!;
              return _buildProfileContent(
                CircleAvatar(
                  radius: 100,
                  child: const Icon(Icons.person, size: 150),
                ),
                userProfile.username,
                userProfile.email,
              );
            }
          },
        ),
      ),
    );
  }

  Widget _buildProfileContent(Widget avatar, String username, String email) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        const SizedBox(height: 30),
        avatar,
        const SizedBox(height: 30),
        Text(
          "Welcome $username !",
          style: const TextStyle(
            fontSize: 24,
            fontWeight: FontWeight.bold,
            fontFamily: 'ClashGrotesk',
          ),
        ),
        const SizedBox(height: 30),
        Text(
          email,
          style: const TextStyle(
            fontSize: 18,
            color: Colors.grey,
            fontFamily: 'ClashGrotesk',
          ),
        ),
      ],
    );
  }

  Widget _buildServiceBoxes(List<Service> services, void Function(String, String) handleConnect) {
    return Expanded(
      flex: 1,
      child: Column(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: services.map((service) {
          return Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Expanded(
                child: ServiceBox(
                  logoPath: service.logoPath,
                  isConnected: service.isConnected,
                  onConnect: () => handleConnect(service.name, service.loginUrl),
                  serviceName: service.name,
                ),
              ),
              if (service.isConnected)
                IconButton(
                  icon: const Icon(Icons.logout),
                  onPressed: () => handleDisconnect(service.name),
                  tooltip: 'Disconnect',
                ),
            ],
          );
        }).toList(),
      ),
    );
  }

  BoxDecoration _boxDecoration() {
    return BoxDecoration(
      color: Colors.white,
      borderRadius: BorderRadius.circular(10),
    );
  }
}