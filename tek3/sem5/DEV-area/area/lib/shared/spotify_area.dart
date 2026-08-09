import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'package:flutter/foundation.dart';
import '../web/area_page.dart';
import '../mobile/mobile_area.dart';
import '../shared/api_service.dart' show getApiUrl;


class SpotifyPage extends StatelessWidget {
  const SpotifyPage({super.key});

  static final List<Tuple3<String, String, Future<String>>> list = [
    Tuple3('When play Spotify song', 'Send message in twitch chat', getApiUrl('api/googlies/area-check-spotify-twitch/')),
    Tuple3('When you play Spotify song', 'Post on Bluesky', getApiUrl('api/googlies/area-check-spotify-bluesky/'))
  ];

  @override
  Widget build(BuildContext context) {
    if (kIsWeb) {
      return ActionReactionPage(
        title: 'Spotify',
        area: list,
      );
    } else {
     return MobileActionReactionPage(
      title: 'spotify',
        area: list,
      );
    }
  }
}
