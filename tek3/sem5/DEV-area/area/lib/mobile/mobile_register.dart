import 'package:flutter/material.dart';
import '../shared/forms_field.dart';
import '../shared/shared_widgets.dart';

class MobileRegister extends StatefulWidget {
  const MobileRegister({super.key});

  @override
  MobileRegisterState createState() => MobileRegisterState();
}

class MobileRegisterState extends State<MobileRegister> {
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
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(20.0),
          child: Container(
            decoration: BoxDecoration(
              border: Border.all(
                color: const Color.fromARGB(255, 140, 211, 255),
                width: 15.0,
              ),
              borderRadius: BorderRadius.circular(30),
            ),
            child: ClipRRect(
              borderRadius: BorderRadius.circular(25),
              child: Container(
                padding: const EdgeInsets.all(20.0),
                color: Colors.white,
                constraints: const BoxConstraints(
                  maxWidth: 400,
                  maxHeight: 550,
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Image.asset(
                        'assets/images/logo_black.png',
                        height: 100,
                      ),
                    const SizedBox(height: 20),
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
      ),
    );
  }
}