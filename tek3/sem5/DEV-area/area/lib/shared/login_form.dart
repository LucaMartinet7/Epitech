import 'package:flutter/material.dart';
import 'platform_conditions.dart';
import '../web/web_login.dart';
import '../mobile/mobile_login.dart';

class LoginPage extends StatelessWidget {
  const LoginPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(""),
        automaticallyImplyLeading: false,
      ),
      body: Center(
        child: SizedBox(
          width: isMobile() ? double.infinity : 800,
          height: isMobile() ? double.infinity : 600,
          child: isMobile() ? const MobileLogin() : const WebLogin(),
        ),
      ),
    );
  }
}