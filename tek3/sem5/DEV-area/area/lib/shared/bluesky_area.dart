import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'package:flutter/foundation.dart';
import '../web/area_page.dart';
import '../mobile/mobile_area.dart';
import '../shared/api_service.dart' show getApiUrl;

class BlueSkyPage extends StatelessWidget {
  const BlueSkyPage({super.key});

  static final List<Tuple3<String, String, Future<String>>> list = [
    Tuple3('When You Post', 'play a song on spotify', getApiUrl('api/googlies/area-check-bluesky-spotify/')),
    Tuple3('When You Post', 'Send Message in your Twitch Chat', getApiUrl('api/googlies/area-check-bluesky-twitch/')),
  ];

  @override
  Widget build(BuildContext context) {
    if (kIsWeb) {
      return ActionReactionPage(
        title: 'BlueSky',
        area: list,
      );
    } else {
      return MobileActionReactionPage(
        title: 'BlueSky',
        area: list,
      );
    }
  }
}