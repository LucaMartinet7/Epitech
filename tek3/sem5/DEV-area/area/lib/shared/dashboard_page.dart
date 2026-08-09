import 'package:flutter/material.dart';
import 'platform_conditions.dart';
import '../mobile/mobile_dashboard.dart';
import '../web/web_dashboard.dart';

class DashboardPage extends StatelessWidget {
  const DashboardPage({super.key});

  @override
  Widget build(BuildContext context) {
    return isMobile() ? const MobileDashboard() : const WebDashboard();
  }
}