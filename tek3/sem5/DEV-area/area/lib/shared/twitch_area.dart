
import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'package:flutter/foundation.dart';
import '../web/area_page.dart';
import '../mobile/mobile_area.dart';
import '../shared/api_service.dart' show getApiUrl;

class TwitchPage extends StatelessWidget {
  const TwitchPage({super.key});

  static final List<Tuple3<String, String, Future<String>>> list = [
    Tuple3('User go live', 'Post to bluesky', getApiUrl('api/twitchs/area-twitchlive-bluesky/')),
    Tuple3('User go live', 'Play Spotify song', getApiUrl('api/twitchs/area-twitchlive-spotify/')),
  ];

  @override
  Widget build(BuildContext context) {
    if (kIsWeb) {
      return ActionReactionPage(
        title: 'Twitch',
        area: list,
      );
    } else {
      return MobileActionReactionPage(
        title: 'twitch',
        area: list,
      );
    }
  }
}