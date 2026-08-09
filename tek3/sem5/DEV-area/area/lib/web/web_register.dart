import 'package:flutter/material.dart';
import '../shared/shared_widgets.dart';
import '../shared/forms_field.dart';

class WebRegister extends StatefulWidget {
  const WebRegister({super.key});

  @override
  WebRegisterState createState() => WebRegisterState();
}

class WebRegisterState extends State<WebRegister> {
  final TextEditingController _nameController = TextEditingController();
  final TextEditingController _emailController = TextEditingController();
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
          width: 1000, // Increased width
          height: 800, // Increased height
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
                  EmailField(controller: _emailController),
                  const SizedBox(height: 20),
                  PasswordField(controller: _passwordController),
                  const SizedBox(height: 20),
                  // const SocialLoginButtons(),
                  const SizedBox(height: 20),
                  RegisterButton(
                    nameController: _nameController,
                    emailController: _emailController,
                    passwordController: _passwordController,
                  ),
                  const SizedBox(height: 20),
                  const LoginLink(),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}
