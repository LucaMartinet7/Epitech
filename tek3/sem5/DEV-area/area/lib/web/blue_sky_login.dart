import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

class BlueSkyLoginPage extends StatefulWidget {
  const BlueSkyLoginPage({super.key});

  @override
  BlueSkyLoginPageState createState() => BlueSkyLoginPageState();
}

class BlueSkyLoginPageState extends State<BlueSkyLoginPage> {
  final _handleController = TextEditingController();
  final _passwordController = TextEditingController();
  final _messageController = TextEditingController();

  @override
  void dispose() {
    _handleController.dispose();
    _passwordController.dispose();
    _messageController.dispose();
    super.dispose();
  }

  void _submit() async {
    final handle = _handleController.text;
    final password = _passwordController.text;
    final message = _messageController.text;

    final response = await http.post(
      Uri.parse('http://127.0.0.1:8000/api/twitchs/setup-bluesky-user/'),
      headers: {
        'Content-Type': 'application/json',
      },
      body: jsonEncode({
        'handle': handle,
        'password': password,
        'message': message,
      }),
    );

    if (!mounted) return;

    if (response.statusCode == 200) {
      Navigator.pushReplacementNamed(context, '/dashboard');
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Failed to setup BlueSky user: ${response.statusCode}')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: _buildAppBar(),
      extendBodyBehindAppBar: true,
      body: Stack(
        children: [
          _buildBackground(),
          _buildLogo(),
          _buildForm(),
        ],
      ),
    );
  }

  AppBar _buildAppBar() {
    return AppBar(
      automaticallyImplyLeading: false,
      backgroundColor: Colors.transparent,
      elevation: 0,
    );
  }

  Widget _buildBackground() {
    return Container(
      color: const Color.fromARGB(255, 128, 196, 252),
    );
  }

  Widget _buildLogo() {
    return Align(
      alignment: Alignment.topCenter,
      child: Padding(
        padding: const EdgeInsets.only(top: 50.0),
        child: Image.asset(
          'assets/images/bluesky.png',
          width: 150,
          height: 150,
        ),
      ),
    );
  }

  Widget _buildForm() {
    return Center(
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 350.0),
        child: Container(
          padding: const EdgeInsets.all(16.0),
          decoration: BoxDecoration(
            color: Colors.white.withOpacity(1),
            borderRadius: BorderRadius.circular(10),
            boxShadow: const [
              BoxShadow(
                color: Colors.black26,
                blurRadius: 10.0,
                spreadRadius: 1.0,
                offset: Offset(0.0, 2.0),
              ),
            ],
          ),
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              _buildTextField(_handleController, 'BlueSky Handle'),
              const SizedBox(height: 16),
              _buildTextField(_passwordController, 'BlueSky Password', obscureText: true),
              const SizedBox(height: 16),
              _buildTextField(_messageController, 'Message'),
              const SizedBox(height: 20),
              _buildSubmitButton(),
            ],
          ),
        ),
      ),
    );
  }

  TextField _buildTextField(TextEditingController controller, String labelText, {bool obscureText = false}) {
    return TextField(
      controller: controller,
      decoration: InputDecoration(
        labelText: labelText,
        border: const OutlineInputBorder(),
      ),
      obscureText: obscureText,
    );
  }

  ElevatedButton _buildSubmitButton() {
    return ElevatedButton(
      onPressed: _submit,
      style: ElevatedButton.styleFrom(
        backgroundColor: const Color.fromARGB(255, 140, 211, 255),
        padding: const EdgeInsets.symmetric(horizontal: 50, vertical: 15),
        textStyle: const TextStyle(fontSize: 18, color: Colors.black),
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(10),
        ),
      ),
      child: const Text(
        'Submit',
        style: TextStyle(color: Colors.black),
      ),
    );
  }
}