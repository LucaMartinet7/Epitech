import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import '../shared/service_name_box.dart';
import 'mobile_nav_bar.dart';
import '../shared/exit_button.dart' show buildExitButton;

class Service {
  final String logoPath;
  final bool isConnected;
  final String route;
  final List<Color> colors;

  Service(this.logoPath, this.isConnected, this.route, this.colors);
}

class MobileDashboard extends StatelessWidget {
  const MobileDashboard({super.key});

  @override
  Widget build(BuildContext context) {
    final services = [
      Service('assets/vectors/spotify.png', true, '/spotify', [const Color(0xFF1DB954)]),
      Service('assets/vectors/twitch.png', false, '/twitch', [const Color(0xFF9146FF)]),
      Service('assets/vectors/google.png', true, '/google', [Colors.blue, Colors.red, Colors.yellow, Colors.green]),
      Service('assets/vectors/youtube.png', true, '/youtube', [const Color(0xFFFF0000)]),
      Service('assets/images/bluesky.png', false, '/bluesky', [Colors.blue, Colors.green, Colors.yellow, Colors.red], ),
    ];

    void handleConnect(BuildContext context, String route) {
      if (kDebugMode) {
        print('Connecting to $route');
      }
      Navigator.pushNamed(context, route);
    }

    return Scaffold(
      appBar: AppBar(
        automaticallyImplyLeading: false,
        actions: [
          buildExitButton(context),
        ],
      ),
      
      body: Center(
        child: SingleChildScrollView(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const SizedBox(height: 15),
              const Text(
                'Available APIs',
                style: TextStyle(
                  fontFamily: 'ClashGrotesk',
                  fontSize: 30,
                  fontWeight: FontWeight.bold,
                ),
              ),
              const SizedBox(height: 20),
            ...services.map((service) {
              return Center(
                child: Card(
                  margin: const EdgeInsets.symmetric(vertical: 30.0),
                  child: Container(
                    constraints: const BoxConstraints(
                      maxWidth: 350,
                      maxHeight: 70,
                    ),
                    child: ServiceNameBox(
                      logoPath: service.logoPath,
                      onConnect: service.isConnected ? () => handleConnect(context, service.route) : () {},
                      backgroundColors: service.isConnected ? service.colors : [Colors.grey],
                    ),
                  ),
                ),
              );
            }),
            ],
          ),
        ),
      ),
      bottomNavigationBar: const MobileNavBar(),
    );
  }
}