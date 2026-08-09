import 'package:flutter/foundation.dart';
import 'package:tuple/tuple.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class ActionReactionRectangle extends StatefulWidget {
  final Tuple3<String, String, Future<String>> actionReaction;
  final Color color;

  const ActionReactionRectangle({
    required this.actionReaction,
    required this.color,
    super.key,
  });

  @override
  ActionReactionRectangleState createState() => ActionReactionRectangleState();
}

class ActionReactionRectangleState extends State<ActionReactionRectangle> {
  bool _hovering = false;
  bool _isActive = false;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        if (kDebugMode) {
          print('Action: ${widget.actionReaction.item1}');
          print('Reaction: ${widget.actionReaction.item2}');
        }
      },
      child: MouseRegion(
        onEnter: (_) => setState(() => _hovering = true),
        onExit: (_) => setState(() => _hovering = false),
        child: AnimatedContainer(
          duration: const Duration(milliseconds: 200),
          decoration: BoxDecoration(
            color: _hovering ? widget.color.withOpacity(0.7) : widget.color,
            borderRadius: BorderRadius.circular(10),
          ),
          child: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 8.0),
                  child: Text(
                    widget.actionReaction.item1,
                    textAlign: TextAlign.center,
                    overflow: TextOverflow.ellipsis,
                    maxLines: 2,
                    style: const TextStyle(fontSize: 20, color: Colors.white, fontFamily: 'ClashGrotesk'),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 8.0),
                  child: Text(
                    widget.actionReaction.item2,
                    textAlign: TextAlign.center,
                    overflow: TextOverflow.ellipsis,
                    maxLines: 2,
                    style: const TextStyle(fontSize: 16, color: Colors.white70, fontFamily: 'ClashGrotesk'),
                  ),
                ),
                Switch(
                  value: _isActive,
                  activeColor: Colors.green,
                  inactiveThumbColor: Colors.red,
                  inactiveTrackColor: Colors.red.withOpacity(0.5),
                  activeTrackColor: Colors.green.withOpacity(0.5),
                  onChanged: (value) async {
                  setState(() => _isActive = value);
                  final url = await widget.actionReaction.item3;
                  try {
                    final response = await http.post(Uri.parse(url), body: {'isActive': value.toString()});
                    if (response.statusCode == 200) {
                    if (kDebugMode) {
                      print('Post successful');
                    }
                    } else {
                    if (kDebugMode) {
                      print('Failed to post: ${response.statusCode}');
                    }
                    }
                  } catch (e) {
                    if (kDebugMode) {
                    print('Error: $e');
                    }
                  }
                  },
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}