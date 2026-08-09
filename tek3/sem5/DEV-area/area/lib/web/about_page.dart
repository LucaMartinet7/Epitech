import 'package:flutter/material.dart';
import 'web_nav_bar.dart';
import '../../shared/api_service.dart' show isLoggedIn;

class WebAboutPage extends StatelessWidget {
  const WebAboutPage({super.key});

  static const double _defaultFontSize = 45;
  static const double _smallFontSize = 25;
  static const double _textPadding = 16.0;
  static const double _sectionPadding = 32.0;
  static const double _buttonPadding = 20.0;
  static const double _imageSize = 400.0;

  TextStyle _buildTextStyle(Color color, {double size = _defaultFontSize, FontWeight fontWeight = FontWeight.bold}) {
    return TextStyle(
      color: color,
      fontSize: size,
      fontWeight: fontWeight,
      fontFamily: 'ClashGrotesk',
    );
  }

  TextSpan _buildTextSpan(String text, Color color, {double size = _defaultFontSize, FontWeight fontWeight = FontWeight.bold, bool outlined = false}) {
    return TextSpan(
      text: text,
      style: outlined
          ? TextStyle(
              fontSize: size,
              fontWeight: fontWeight,
              fontFamily: 'ClashGrotesk',
              foreground: Paint()
                ..style = PaintingStyle.stroke
                ..strokeWidth = 3
                ..color = Colors.black,
            )
          : _buildTextStyle(color, size: size, fontWeight: fontWeight),
    );
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder<bool>(
      future: isLoggedIn(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator());
        } else if (snapshot.hasError) {
          return const Center(child: Text('Error checking user status'));
        } else {
          return Scaffold(
            appBar: snapshot.data == true ? const WebNavBar() : null,
            backgroundColor: const Color(0xFFF1F4F6),
            body: SafeArea(
              child: SingleChildScrollView(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    const SizedBox(height: 100),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: _textPadding),
                      child: _buildMainContent(),
                    ),
                    const SizedBox(height: 20),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: _textPadding),
                      child: _buildRegisterSection(context),
                    ),
                    const SizedBox(height: 80),
                    _buildDownloadSection(),
                  ],
                ),
              ),
            ),
          );
        }
      },
    );
  }

  Widget _buildMainContent() {
    return Padding(
      padding: const EdgeInsets.only(left: 100.0, right: 8.0),
      child: Row(
        children: [
          Expanded(
            child: Stack(
              children: [
                RichText(
                  text: TextSpan(
                    children: [
                      _buildTextSpan("Effortlessly manage your\ndigital ecosystem, where\n", Colors.transparent),
                      _buildTextSpan("automation", Colors.transparent, outlined: true),
                      _buildTextSpan(" meets ", Colors.transparent),
                      _buildTextSpan("simplicity", Colors.transparent, outlined: true),
                      _buildTextSpan(".", Colors.transparent),
                    ],
                  ),
                ),
                RichText(
                  text: TextSpan(
                    children: [
                      _buildTextSpan("Effortlessly manage your\ndigital ecosystem, where\n", Colors.black),
                      _buildTextSpan("automation", const Color(0xFFF1F4F6)),
                      _buildTextSpan(" meets ", Colors.black),
                      _buildTextSpan("simplicity", const Color(0xFFF1F4F6)),
                      _buildTextSpan(".", Colors.black),
                      _buildTextSpan(
                        "\n\nStreamline your digital experience.\nWorkflows that enhance productivity.\nAutomate actions and reactions across services.",
                        Colors.black,
                        size: 16,
                        fontWeight: FontWeight.normal,
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ),
          const SizedBox(width: 32),
          Expanded(
            child: Image.asset(
              'assets/images/logo_black.png',
              width: _imageSize,
              height: _imageSize,
              fit: BoxFit.contain,
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildRegisterSection(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(left: 100.0, right: 8.0),
      child: Row(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Expanded(
            child: Stack(
              children: [
                RichText(
                  text: TextSpan(
                    children: [
                      _buildTextSpan("Sound Fun?", Colors.transparent),
                      _buildTextSpan("\nRegister the ", Colors.transparent, size: _smallFontSize, fontWeight: FontWeight.normal),
                      _buildTextSpan("Nell Dashboard", Colors.transparent, size: _smallFontSize, fontWeight: FontWeight.normal, outlined: true),
                      _buildTextSpan(" Today!", Colors.transparent, size: _smallFontSize, fontWeight: FontWeight.normal),
                    ],
                  ),
                ),
                RichText(
                  text: TextSpan(
                    children: [
                      _buildTextSpan("Sound Fun?", Colors.black),
                      _buildTextSpan("\nRegister the ", Colors.black, size: _smallFontSize, fontWeight: FontWeight.normal),
                      _buildTextSpan("Nell Dashboard", const Color(0xFFF1F4F6), size: _smallFontSize, fontWeight: FontWeight.normal),
                      _buildTextSpan(" Today!", Colors.black, size: _smallFontSize, fontWeight: FontWeight.normal),
                    ],
                  ),
                ),
              ],
            ),
          ),
          const SizedBox(width: 32),
          Flexible(
            fit: FlexFit.loose,
            child: Align(
              alignment: Alignment.center,
              child: _buildButtons(context),
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildButtons(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.start,
      children: [
        Expanded(
          child: ElevatedButton(
            onPressed: () {
              Navigator.pushNamed(context, '/register');
            },
            style: ElevatedButton.styleFrom(
              backgroundColor: const Color.fromARGB(255, 140, 211, 255),
              padding: const EdgeInsets.symmetric(horizontal: 30, vertical: _buttonPadding),
              textStyle: _buildTextStyle(Colors.white, size: 20),
              foregroundColor: Colors.black,
            ),
            child: const Text("Register"),
          ),
        ),
        const SizedBox(width: 16),
        Text(
          "or",
          style: _buildTextStyle(Colors.black, size: 24, fontWeight: FontWeight.normal),
        ),
        const SizedBox(width: 16),
        Expanded(
          child: ElevatedButton(
            onPressed: () {
              Navigator.pushNamed(context, '/login');
            },
            style: ElevatedButton.styleFrom(
              backgroundColor: const Color.fromARGB(255, 140, 211, 255),
              padding: const EdgeInsets.symmetric(horizontal: 40, vertical: _buttonPadding),
              textStyle: _buildTextStyle(Colors.white, size: 20),
              foregroundColor: Colors.black,
            ),
            child: const Text("Login"),
          ),
        ),
      ],
    );
  }


  Widget _buildDownloadSection() {
    return LayoutBuilder(
      builder: (context, constraints) {
        return Container(
          width: double.infinity,
          padding: const EdgeInsets.all(_sectionPadding),
          color: const Color.fromARGB(255, 140, 211, 255),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Text(
                "Want to take your automations on the move?",
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 32,
                  fontWeight: FontWeight.normal,
                  fontFamily: 'ClashGrotesk',
                ),
              ),
              const SizedBox(width: 16),
              ElevatedButton(
                onPressed: () {
                  // Download APK
                },
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color.fromRGBO(49, 49, 49, 1),
                  padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 30),
                  textStyle: _buildTextStyle(Colors.white, size: 20),
                  foregroundColor: Colors.white,
                ),
                child: const Text("Download the APK"),
              ),
            ],
          ),
        );
      },
    );
  }
}