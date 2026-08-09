import 'package:flutter/material.dart';

class MobileNavBar extends StatelessWidget {
  const MobileNavBar({super.key});

  int _getSelectedIndex(BuildContext context) {
    final String currentRoute = ModalRoute.of(context)?.settings.name ?? '';
    switch (currentRoute) {
      case '/dashboard':
        return 1;
      case '/account':
        return 2;
      default:
        return 0;
    }
  }

  @override
  Widget build(BuildContext context) {
    int selectedIndex = _getSelectedIndex(context);

    return BottomNavigationBar(
      currentIndex: selectedIndex,
      items: const [
        BottomNavigationBarItem(
          icon: Icon(Icons.arrow_back),
          label: 'Back',
        ),
        BottomNavigationBarItem(
          icon: Icon(Icons.dashboard),
          label: 'Dashboard',
        ),
        BottomNavigationBarItem(
          icon: Icon(Icons.account_circle),
          label: 'Account',
        )
      ],
      onTap: (index) {
        switch (index) {
          case 0:
            Navigator.pop(context);
            break;
          case 1:
            Navigator.pushNamed(context, '/dashboard');
            break;
          case 2:
            Navigator.pushNamed(context, '/account');
            break;
        }
      },
    );
  }
}