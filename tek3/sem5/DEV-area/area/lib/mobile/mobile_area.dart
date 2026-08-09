import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'dart:math';
import '../shared/area_rectangle.dart';
import 'mobile_nav_bar.dart';

class MobileActionReactionPage extends StatelessWidget {
  final String title;
  final List<Tuple3<String, String, Future<String>>> area;

  const MobileActionReactionPage({
    required this.title,
    required this.area,
    super.key,
  });

  Color _getRandomColor() {
    final Random random = Random();
    Color color;
    do {
      color = Color.fromARGB(
        255,
        random.nextInt(256),
        random.nextInt(256),
        random.nextInt(256),
      );
    } while (_isColorTooLight(color));
    return color;
  }

  bool _isColorTooLight(Color color) {
    double luminance = (0.299 * color.red + 0.587 * color.green + 0.114 * color.blue) / 255;
    return luminance > 0.7;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        automaticallyImplyLeading: false,
      ),
      body: Center(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(20.0),
            child: Column(
            children: [
              Image.asset(
              'assets/vectors/$title.png',
              height: 50,
              ),
              const SizedBox(height: 20),
              ...area.map((actionReaction) {
                return Padding(
                  padding: const EdgeInsets.symmetric(vertical: 10.0),
                  child: SizedBox(
                    height: 200,
                    width: 400,
                    child: ActionReactionRectangle(
                      actionReaction: actionReaction,
                      color: _getRandomColor(),
                    ),
                  ),
                );
              }),
            ],
          ),
        ),
      ),
      bottomNavigationBar: const MobileNavBar(),
    );
  }
}