import 'package:flutter/material.dart';

class ServiceBox extends StatelessWidget {
  final String logoPath;
  final bool isConnected;
  final VoidCallback onConnect;
  final String serviceName;

  const ServiceBox({
    required this.logoPath,
    required this.isConnected,
    required this.onConnect,
    required this.serviceName,
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(8.0),
      height: 150,
      decoration: _boxDecoration(serviceName),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Image.asset(
            logoPath,
            height: 40,
          ),
          const SizedBox(width: 10),
          GestureDetector(
            onTap: isConnected ? null : onConnect,
            child: Text(
              isConnected ? 'Connected' : 'Connect',
              style: TextStyle(
                color: isConnected ? Colors.green : Colors.red,
                fontSize: 32,
                fontWeight: FontWeight.bold,
                fontFamily: 'ClashGrotesk',
              ),
            ),
          ),
        ],
      ),
    );
  }

  BoxDecoration _boxDecoration(String serviceName) {
    Color borderColor;

    switch (serviceName) {
      case 'Spotify':
        borderColor = const Color(0xFF1DB954);
        break;
      case 'Twitch':
        borderColor = const Color(0xFF9146FF);
        break;
      case 'Bluesky':
        borderColor = Colors.blue;
        break;
      case 'Youtube':
        borderColor = const Color(0xFFFF0000);
        break;
      case 'Google':
        borderColor = Colors.orange;
        break;
      default:
        borderColor = Colors.grey;
    }

    return BoxDecoration(
      color: Colors.white,
      borderRadius: BorderRadius.circular(10),
      border: Border.all(color: borderColor, width: 5),
      boxShadow: [
        BoxShadow(
          color: Colors.grey.withOpacity(0.5),
          spreadRadius: 2,
          blurRadius: 5,
          offset: const Offset(0, 3),
        ),
      ],
    );
  }
}