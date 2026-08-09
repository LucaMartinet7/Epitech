import 'package:flutter/material.dart';
import '../shared/shared_widgets.dart';
import '../shared/forms_field.dart';

class WebLogin extends StatefulWidget {
  const WebLogin({super.key});

  @override
  WebLoginState createState() => WebLoginState();
}

class WebLoginState extends State<WebLogin> {
  final TextEditingController _nameController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        automaticallyImplyLeading: false,
        actions: [
          IconButton(
            icon: const Icon(Icons.info),
            onPressed: () {
              Navigator.pushNamed(context, '/about');
            },
          ),
        ],
      ),
      body: Center(
        child: SizedBox(
          width: 800,
          height: 600,
          child: InfoContainer(
            child: AuthContainer(
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Image.asset(
                        'assets/images/logo_black.png',
                        height: 100,
                      ),
                  NameField(controller: _nameController),
                  const SizedBox(height: 20),
                  PasswordField(controller: _passwordController),
                  const SizedBox(height: 20),
                  // const SocialLoginButtons(),
                  const SizedBox(height: 20),
                  LoginButton(
                    nameController: _nameController,
                    passwordController: _passwordController,
                  ),
                  const SizedBox(height: 20),
                  const RegisterLink(),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}