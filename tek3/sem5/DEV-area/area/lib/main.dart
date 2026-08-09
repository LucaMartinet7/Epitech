import 'package:flutter/material.dart';
import 'package:nell/web/route_guard.dart';
import 'shared/login_form.dart';
import 'shared/register_form.dart';
import 'shared/dashboard_page.dart';
import 'web/blue_sky_login.dart';
import 'shared/about_page.dart';
import 'shared/spotify_area.dart';
import 'shared/twitch_area.dart';
import 'shared/google_area.dart';
import 'shared/youtube_area.dart';
import 'mobile/mobile_account.dart';
import 'package:url_strategy/url_strategy.dart';
import 'shared/bluesky_area.dart';
import 'shared/api_service.dart' show isLoggedIn;


void main() {
  setPathUrlStrategy();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: FutureBuilder<bool>(
        future: isLoggedIn(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const CircularProgressIndicator();
          } else if (snapshot.hasData && snapshot.data == true) {
            return const DashboardPage();
          } else {
            return const AboutPage();
          }
        },
      ),
      routes: {
        '/login': (context) => const LoginPage(),
        '/register': (context) => const RegisterPage(),
        '/about': (context) => const AboutPage(),
        '/dashboard': (context) => RouteGuard(child: const DashboardPage()),
        '/spotify': (context) => RouteGuard(child: const SpotifyPage()),
        '/twitch': (context) => RouteGuard(child: const TwitchPage()),
        '/google': (context) => RouteGuard(child: const GooglePage()),
        '/youtube': (context) => RouteGuard(child: const YoutubePage()),
        '/account': (context) => RouteGuard(child: const MobileAccount()),
        '/bluesky': (context) => RouteGuard(child: const BlueSkyPage()),
        '/bluesky/login': (context) => RouteGuard(child: const BlueSkyLoginPage()),
      },
    );
  }
}