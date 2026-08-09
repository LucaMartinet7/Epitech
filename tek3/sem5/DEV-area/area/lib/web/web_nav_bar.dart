import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import '../shared/exit_button.dart';

const List<Map<String, String>> services = [
  {'asset': 'assets/vectors/account.png', 'route': '/dashboard', 'name': 'Account'},
  {'asset': 'assets/vectors/spotify.png', 'route': '/spotify', 'name': 'Spotify'},
  {'asset': 'assets/vectors/twitch.png', 'route': '/twitch', 'name': 'Twitch'},
  {'asset': 'assets/vectors/google.png', 'route': '/google', 'name': 'Google'},
  {'asset': 'assets/vectors/youtube.png', 'route': '/youtube', 'name': 'YouTube'},
  {'asset': 'assets/vectors/microsoft.png', 'route': '/microsoft', 'name': 'Microsoft'},
  {'asset': 'assets/images/bluesky.png', 'route': '/bluesky', 'name': 'Bluesky'},
];

class WebNavBar extends StatelessWidget implements PreferredSizeWidget {
  const WebNavBar({super.key});

  Future<List<Map<String, String>>> _getConnectedServices() async {
    final prefs = await SharedPreferences.getInstance();
    final connectedServices = services.where((service) {
      final name = service['name']!;
      return name == 'Account' || (prefs.getBool(name) ?? false);
    }).toList();
    return connectedServices;
  }

  @override
  Widget build(BuildContext context) {
    final currentRoute = ModalRoute.of(context)?.settings.name;

    return FutureBuilder<List<Map<String, String>>>(
      future: _getConnectedServices(),
      builder: (context, snapshot) {
        if (!snapshot.hasData) return const SizedBox(); // Display nothing while loading

        return Container(
          decoration: BoxDecoration(
            border: Border.all(color: const Color.fromARGB(255, 140, 211, 255), width: 5),
          ),
          child: AppBar(
            backgroundColor: Colors.transparent,
            elevation: 0,
            leading: buildExitButton(context),
            flexibleSpace: Row(
              children: [
                Expanded(
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: snapshot.data!.map((service) {
                      return _buildNavButton(
                        context,
                        service['asset']!,
                        service['route']!,
                        isCurrent: currentRoute == service['route'],
                      );
                    }).toList(),
                  ),
                ),
                _buildNavButton(context, 'assets/vectors/info.png', '/about', isCurrent: currentRoute == '/about'),
              ],
            ),
          ),
        );
      },
    );
  }

  Widget _buildNavButton(BuildContext context, String assetPath, String route, {required bool isCurrent}) {
    return IconButton(
      onPressed: ModalRoute.of(context)?.settings.name != route
          ? () => Navigator.pushNamed(context, route)
          : null,
      icon: Image.asset(
        assetPath,
        width: 32,
        height: 32,
        color: isCurrent ? Colors.blue : const Color.fromARGB(255, 140, 211, 255),
      ),
    );
  }

  @override
  Size get preferredSize => const Size.fromHeight(kToolbarHeight);
}
