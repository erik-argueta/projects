import 'package:flutter/material.dart';

void main() {
  runApp(
    const MaterialApp(
      home: MyApp(),
    ),
  );
}

/*

  
  - Begin Navigation Set-up
      * Language-Page [Only show up at first initialization of the app]
      * Main Menu
      * Vacc Sites
      * Test Sites
      * Food Drive
      * Town Halls
      * Settings -> Change language?
      
  - Find way to cycle the [Please Select a Language]
*/

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Language Selection',
      theme: ThemeData(
        scaffoldBackgroundColor: const Color.fromARGB(255, 54, 57, 63),
        colorScheme:
            ColorScheme.fromSwatch(primarySwatch: Colors.green).copyWith(
          secondary: Colors.green,
        ),
      ),
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Please Select a Language'),
        ),
        body: Center(
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: <Widget>[
              // ENGLISH
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  padding: const EdgeInsets.only(
                    left: (46.5),
                    right: (46.5),
                  ),
                  textStyle: const TextStyle(fontSize: 30),
                ),
                onPressed: () {},
                child: const Text('English'),
              ),
              // SPANISH
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  padding: const EdgeInsets.only(
                    left: (42),
                    right: (42),
                  ),
                  textStyle: const TextStyle(fontSize: 30),
                ),
                onPressed: () {},
                child: const Text('Espanol'),
              ),
              // MANDARIN
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  padding: const EdgeInsets.only(
                    left: 32,
                    right: 32,
                  ),
                  textStyle: const TextStyle(fontSize: 30),
                ),
                onPressed: () {},
                child: const Text('Mandarin'),
              ),
              // VIETNAMESE
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  textStyle: const TextStyle(fontSize: 30),
                ),
                onPressed: () {},
                child: const Text('Vietnamese'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
