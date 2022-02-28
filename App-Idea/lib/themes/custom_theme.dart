import 'package:flutter/material.dart';
//import 'colors.dart';

class CustomTheme {
  static ThemeData get basicTheme {
    return ThemeData(
        primaryColor: Colors.green,
        scaffoldBackgroundColor: const Color.fromARGB(255, 54, 57, 63));
  }
}

final ButtonStyle testing = ElevatedButton.styleFrom(
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
