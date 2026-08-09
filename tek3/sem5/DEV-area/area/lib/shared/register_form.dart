import 'package:flutter/material.dart';
import 'platform_conditions.dart';
import '../web/web_register.dart';
import '../mobile/mobile_register.dart';

class RegisterPage extends StatelessWidget {
  const RegisterPage({super.key});

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
          child: isMobile() ? const MobileRegister() : const WebRegister(),
        ),
      ),
    );
  }
}