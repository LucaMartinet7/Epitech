import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';
import 'package:url_launcher/url_launcher.dart';
import '../shared/service_box.dart';
import '../shared/user_service.dart';
import 'mobile_nav_bar.dart';
import '../shared/exit_button.dart' show buildExitButton;
import '../shared/api_service.dart' show getApiUrl;

class Service {
  final String name;
  final String logoPath;
  bool isConnected;
  final Future<String> loginUrl;

  Service(this.name, this.logoPath, this.isConnected, this.loginUrl);
}

class MobileAccount extends StatelessWidget {
  const MobileAccount({super.key});

  @override
  Widget build(BuildContext context) {
    final services = [
      Service('Spotify', 'assets/images/spotify.png', false, getApiUrl('api/auth/spotify/login/')),
      Service('Twitch', 'assets/images/twitch.png', false, getApiUrl('api/auth/twitch/login/')),
      Service('Google', 'assets/images/google.png', false, getApiUrl('api/auth/google/login/')),
      Service('Bluesky', 'assets/images/bluesky.png', false, Future.value('http://localhost:3000/bluesky/login')),
    ];

    void handleConnect(Service service) async {
      if (kDebugMode) {
        print('Connecting to ${service.name}');
      }
      final url = await service.loginUrl;
      if (await canLaunchUrl(Uri.parse(url))) {
        await launchUrl(Uri.parse(url));
        service.isConnected = true;
      } else {
        if (kDebugMode) {
          print('Could not launch $url');
        }
      }
    }

    return Scaffold(
      appBar: AppBar(
        automaticallyImplyLeading: false,
        leading: _buildAboutButton(context),
        actions: [
          buildExitButton(context),
        ],
      ),
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
                return Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    _buildProfile(context, username),
                    const SizedBox(height: 16),
                    _buildServiceBoxes(services, handleConnect),
                  ],
                );
              }
            },
          ),
        ),
      ),
      bottomNavigationBar: const MobileNavBar(),
    );
  }

  Widget _buildAboutButton(BuildContext context) {
    return IconButton(
      icon: const Icon(Icons.info_outline),
      onPressed: () {
        Navigator.pushNamed(context, '/about');
      },
    );
  }

  Widget _buildProfile(BuildContext context, String username) {
    return Container(
      width: double.infinity,
      padding: const EdgeInsets.all(16.0),
      child: FutureBuilder<UserProfile>(
        future: fetchUserProfile(username),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const CircularProgressIndicator();
          } else if (snapshot.hasError) {
            return _buildProfileContent(
              CircleAvatar(
                radius: 50,
                child: const Icon(Icons.person, size: 50),
              ),
              'Error',
              'error@example.com',
            );
          } else if (!snapshot.hasData) {
            return _buildProfileContent(
              CircleAvatar(
                radius: 50,
                child: const Icon(Icons.person, size: 50),
              ),
              'No Data',
              'nodata@example.com',
            );
          } else {
            final userProfile = snapshot.data!;
            return _buildProfileContent(
              CircleAvatar(
                radius: 50,
                backgroundImage: NetworkImage(userProfile.profileImagePath),
              ),
              userProfile.username,
              userProfile.email,
            );
          }
        },
      ),
    );
  }

  Widget _buildProfileContent(Widget avatar, String username, String email) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        const SizedBox(height: 10),
        avatar,
        const SizedBox(height: 10),
        Text(
          "Welcome $username !",
          style: const TextStyle(
            fontSize: 20,
            fontFamily: 'ClashGrotesk',
          ),
        ),
        const SizedBox(height: 10),
        Text(
          email,
          style: const TextStyle(
            fontSize: 16,
            color: Colors.grey,
            fontFamily: 'ClashGrotesk',
          ),
        ),
      ],
    );
  }

  Widget _buildServiceBoxes(List<Service> services, void Function(Service) handleConnect) {
    return Expanded(
      child: ListView.builder(
        padding: const EdgeInsets.all(20.0),
        itemCount: services.length,
        itemBuilder: (context, index) {
          final service = services[index];
          return Card(
            margin: const EdgeInsets.symmetric(vertical: 20.0),
            child: Center(
              child: Container(
                constraints: const BoxConstraints(
                  maxHeight: 80,
                ),
                child: ServiceBox(
                  logoPath: service.logoPath,
                  isConnected: service.isConnected,
                  serviceName: service.name,
                  onConnect: () => handleConnect(service),
                ),
              ),
            ),
          );
        },
      ),
    );
  }
}