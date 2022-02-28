import 'package:flutter/material.dart';
import 'languagesEN/english/english_main.dart';
import 'languagesEN/english/vax_sites_en.dart';
import 'themes/custom_theme.dart';

void main() {
  runApp(
    MaterialApp(
      title: 'Testing Routes',
      initialRoute: '/',
      // Start the app with "/" route, build the LanguageScreen widget.
      routes: {
        '/': (context) => const LanguageScreen(),
        // when navigating to the "/second" route, build the EnglishBuild
        '/engl': (context) => const EnglishMain(),
        // Vax Sites Route
        '/vaxSites': (context) => const VaccinationSites(),
      },
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

class LanguageScreen extends StatelessWidget {
  const LanguageScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Language Selection',
      theme: CustomTheme.basicTheme,
      home: Scaffold(
        appBar: AppBar(
          centerTitle: true,
          backgroundColor: CustomTheme.basicTheme.primaryColor,
          title: const Text(
            'Please Select a Language',
            style: TextStyle(
              fontSize: 28,
              fontWeight: FontWeight.w400,
            ),
          ),
        ),
        body: Center(
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: <Widget>[
              // ENGLISH
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  primary: CustomTheme.basicTheme.primaryColor,
                  padding: const EdgeInsets.only(
                    top: 15,
                    bottom: 15,
                    left: (46.5),
                    right: (46.5),
                  ),
                  textStyle: const TextStyle(
                    fontSize: 30,
                  ),
                ),
                // Within the 'LanguageScreen' widget
                onPressed: () {
                  // Navigate to teh second screen using a named route
                  Navigator.pushNamed(context, '/engl');
                },
                child: const Text('English'),
              ),
              const SizedBox(height: 50),

              // SPANISH
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  primary: CustomTheme.basicTheme.primaryColor,
                  padding: const EdgeInsets.only(
                    top: 15,
                    bottom: 15,
                    left: (42),
                    right: (42),
                  ),
                  textStyle: const TextStyle(
                    fontSize: 30,
                  ),
                ),
                onPressed: () {},
                child: const Text('Espanol'),
              ),
              const SizedBox(height: 50),

              // MANDARIN
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  primary: CustomTheme.basicTheme.primaryColor,
                  padding: const EdgeInsets.only(
                    top: 15,
                    bottom: 15,
                    left: 32,
                    right: 32,
                  ),
                  textStyle: const TextStyle(fontSize: 30),
                ),
                onPressed: () {},
                child: const Text('Mandarin'),
              ),
              const SizedBox(height: 50),

              // VIETNAMESE
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                  primary: CustomTheme.basicTheme.primaryColor,
                  padding: const EdgeInsets.only(
                    top: 15,
                    bottom: 15,
                    left: 16,
                    right: 16,
                  ),
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
