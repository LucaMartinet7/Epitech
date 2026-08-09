import 'package:flutter/material.dart';
import 'mobile_nav_bar.dart';
import '../shared/api_service.dart' show isLoggedIn;

class MobileAboutPage extends StatelessWidget {
  const MobileAboutPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        automaticallyImplyLeading: false,
        title: const Text(
          'About',
          style: TextStyle(
            fontFamily: 'ClashGrotesk',
            fontSize: 24,
            fontWeight: FontWeight.bold,
          ),
        ),
        centerTitle: true,
      ),
      body: Center(
        child: SingleChildScrollView(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              _buildLogo(),
              const SizedBox(height: 30),
              _buildDescription(),
              const SizedBox(height: 30),
              _buildFeatures(),
              const SizedBox(height: 30),
              FutureBuilder<bool>(
                future: isLoggedIn(),
                builder: (context, snapshot) {
                  if (snapshot.connectionState == ConnectionState.waiting) {
                    return const SizedBox.shrink(); // or a loading indicator
                  } else if (snapshot.hasData && snapshot.data == false) {
                    return Column(
                      children: [
                        _buildBanner(context),
                        const SizedBox(height: 30),
                        _buildActionButtons(context),
                      ],
                    );
                  } else {
                    return const SizedBox.shrink();
                  }
                },
              ),
            ],
          ),
        ),
      ),
      bottomNavigationBar: FutureBuilder<bool>(
        future: isLoggedIn(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const SizedBox.shrink(); // or a loading indicator
          } else if (snapshot.hasData && snapshot.data == true) {
            return const MobileNavBar();
          } else {
            return const SizedBox.shrink();
          }
        },
      ),
    );
  }

  Widget _buildLogo() {
    return Image.asset(
      'assets/images/logo_black.png',
      height: 100,
    );
  }

  Widget _buildDescription() {
    return const Padding(
      padding: EdgeInsets.symmetric(horizontal: 20.0),
      child: Text(
        'Effortlessly manage your digital ecosystem where automation meets simplicity',
        style: TextStyle(
          fontFamily: 'ClashGrotesk',
          fontSize: 38,
        ),
        textAlign: TextAlign.left,
      ),
    );
  }

  Widget _buildBanner(BuildContext context) {
    return Container(
      width: MediaQuery.of(context).size.width,
      height: 80,
      color: const Color.fromARGB(255, 140, 211, 255),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: const [
          Text(
            'Sounds Fun?',
            style: TextStyle(
              fontFamily: 'ClashGrotesk',
              fontSize: 24,
              fontWeight: FontWeight.bold,
              color: Colors.white,
            ),
          ),
          Text(
            'Register the Nell Dashboard today!',
            style: TextStyle(
              fontFamily: 'ClashGrotesk',
              fontSize: 16,
              color: Colors.white,
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildFeatures() {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: const [
        Text(
          'Features:',
          style: TextStyle(
            fontFamily: 'ClashGrotesk',
            fontSize: 30,
            fontWeight: FontWeight.bold,
          ),
        ),
        SizedBox(height: 10),
        Text(
          '- Connect multiple APIs\n'
          '- Automate tasks between services\n'
          '- Create custom workflows\n'
          '- Streamline your processes',
          style: TextStyle(
            fontFamily: 'ClashGrotesk',
            fontSize: 24,
          ),
          textAlign: TextAlign.left,
        ),
      ],
    );
  }

  Widget _buildActionButtons(BuildContext context) {
    final ButtonStyle buttonStyle = ElevatedButton.styleFrom(
      backgroundColor: const Color.fromARGB(255, 140, 211, 255), // Background color
      foregroundColor: Colors.white, // Text color
      padding: const EdgeInsets.symmetric(horizontal: 30, vertical: 15),
      textStyle: const TextStyle(
        fontFamily: 'ClashGrotesk',
        fontSize: 16,
        fontWeight: FontWeight.bold,
      ),
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(10.0), // Rounded corners
      ),
    );

    return Padding(
      padding: const EdgeInsets.symmetric(horizontal: 30.0, vertical: 30.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        children: [
          ElevatedButton(
            style: buttonStyle,
            onPressed: () {
              Navigator.pushNamed(context, '/register');
            },
            child: const Text('Register'),
          ),
          const Text(
          'or',
          style: TextStyle(
            fontFamily: 'ClashGrotesk',
            fontSize: 24,
          ),
        ),
          ElevatedButton(
            style: buttonStyle,
            onPressed: () {
              Navigator.pushNamed(context, '/login');
            },
            child: const Text('Login'),
          ),
        ],
      ),
    );
  }
}