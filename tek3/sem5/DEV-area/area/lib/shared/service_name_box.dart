import 'package:flutter/material.dart';

class ServiceNameBox extends StatelessWidget {
  final String logoPath;
  final VoidCallback onConnect;
  final List<Color> backgroundColors;

  const ServiceNameBox({
    required this.logoPath,
    required this.onConnect,
    required this.backgroundColors,
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onConnect,
      child: Container(
        height: 150,
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10.0),
        ),
        child: Stack(
          children: [
            Row(
              children: backgroundColors.map((color) {
                return Expanded(
                  child: Container(
                    decoration: BoxDecoration(
                      color: color,
                      borderRadius: backgroundColors.length == 1
                          ? BorderRadius.circular(10.0)
                          : backgroundColors.indexOf(color) == 0
                              ? const BorderRadius.only(
                                  topLeft: Radius.circular(10.0),
                                  bottomLeft: Radius.circular(10.0),
                                )
                              : backgroundColors.indexOf(color) == backgroundColors.length - 1
                                  ? const BorderRadius.only(
                                      topRight: Radius.circular(10.0),
                                      bottomRight: Radius.circular(10.0),
                                    )
                                  : BorderRadius.zero,
                    ),
                  ),
                );
              }).toList(),
            ),
            Center(
              child: Image.asset(
                logoPath,
                height: 40,
              ),
            ),
          ],
        ),
      ),
    );
  }
}