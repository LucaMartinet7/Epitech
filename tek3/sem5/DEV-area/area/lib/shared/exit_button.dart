import 'package:flutter/material.dart';
import '../shared/api_service.dart';
import '../web/web_dashboard.dart';

Widget buildExitButton(BuildContext context) {
  return IconButton(
    onPressed: () async {
      final state = context.findAncestorStateOfType<WebDashboardState>();
      if (state != null) {
        state.resetConnections();
      }
      await logout(context);
    },
    icon: Image.asset(
      'assets/vectors/exit.png',
      width: 32,
      height: 32,
      color: const Color.fromARGB(255, 140, 211, 255),
    ),
  );
}