import 'package:flutter/material.dart';
//import 'colors.dart';

class CustomTheme {
  static ThemeData get basicTheme {
    return ThemeData(
      primaryColor: Colors.green,
      scaffoldBackgroundColor: const Color.fromARGB(255, 54, 57, 63),
      backgroundColor: const Color.fromARGB(255, 47, 49, 54),
      dividerColor: const Color.fromARGB(255, 30, 30, 30),
    );
  }
}

// Basic Button Style
final ButtonStyle basicButton = ElevatedButton.styleFrom(
    primary: CustomTheme.basicTheme.primaryColor,
    padding: const EdgeInsets.only(
      top: 15,
      bottom: 15,
      left: 42,
      right: 42,
    ),
    textStyle: const TextStyle(
      fontSize: 30,
    ));

// For the drawer section
const TextStyle nonselectedTile = TextStyle(
  fontSize: 27,
  color: Color.fromARGB(255, 135, 139, 144),
  fontWeight: FontWeight.w400,
);

const TextStyle selectedTile = TextStyle(
  color: Color.fromARGB(255, 247, 247, 247),
  fontSize: 27,
  fontWeight: FontWeight.w400,
);

final Divider drawerDivider = Divider(
  color: CustomTheme.basicTheme.dividerColor,
  height: 3,
  thickness: 1.5,
);
