import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'package:flutter/foundation.dart';
import '../web/area_page.dart';
import '../mobile/mobile_area.dart';
import '../shared/api_service.dart' show getApiUrl;


class YoutubePage extends StatelessWidget {
  const YoutubePage({super.key});

  static final List<Tuple3<String, String, Future<String>>> list = [
    Tuple3('Follow a youtube channel', 'Post on Bluesky', getApiUrl('googlies/area-check-youtube-bluesky/')),
    Tuple3('Follow a youtube channel', 'Play music on Spotify', getApiUrl('googlies/area-check-youtube-spotify/')),
    Tuple3('Follow a youtube channel', 'Send a message in twitch chat', getApiUrl('googlies/area-check-youtube-twitch/'))
  ];

  @override
  Widget build(BuildContext context) {
    if (kIsWeb) {
      return ActionReactionPage(
        title: 'YouTube',
        area: list,
      );
    } else {
      return MobileActionReactionPage(
        title: 'youtube',
        area: list,
      );
    }
  }
}