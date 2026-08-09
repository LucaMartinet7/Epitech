import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'package:flutter/foundation.dart';
import '../web/area_page.dart';
import '../mobile/mobile_area.dart';
import '../shared/api_service.dart' show getApiUrl;

class GooglePage extends StatelessWidget {
  const GooglePage({super.key});

  static final List<Tuple3<String, String, Future<String>>> list = [
    Tuple3('Send an email', 'Post on Bluesky', getApiUrl('googlies/area-check-gmail-bluesky/')),
    Tuple3('Send an email', 'Play music on Spotify', getApiUrl('googlies/area-check-gmail-spotify/')),
    Tuple3('Send an email', 'Type in twitch channel', getApiUrl('googlies/area-check-gmail-twitch/'))
  ];

  @override
  Widget build(BuildContext context) {
    if (kIsWeb) {
      return ActionReactionPage(
        title: 'Google',
        area: list,
      );
    } else {
      return MobileActionReactionPage(
        title: 'google',
        area: list,
      );
    }
  }
}