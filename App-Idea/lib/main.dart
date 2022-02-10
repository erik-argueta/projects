import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'Language Selection',
        home: Scaffold(
            backgroundColor: const Color.fromARGB(255, 54, 57, 63),
            appBar: AppBar(
              backgroundColor: Color.fromARGB(255, 204, 0, 0),
              centerTitle: true,
              title: const Text('Select a Language'),
            )));
  }
}
