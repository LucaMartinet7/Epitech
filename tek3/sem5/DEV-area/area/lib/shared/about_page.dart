import 'package:flutter/material.dart';
import 'platform_conditions.dart';
import '../mobile/mobile_about.dart';
import '../web/about_page.dart';

class AboutPage extends StatelessWidget {
  const AboutPage({super.key});

  @override
  Widget build(BuildContext context) {
    return isMobile() ? const MobileAboutPage() : const WebAboutPage();
  }
}
