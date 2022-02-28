import 'package:flutter/material.dart';
import 'package:macbook_el_monte/themes/custom_theme.dart';

class EnglishMain extends StatelessWidget {
  const EnglishMain({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: CustomTheme.basicTheme.scaffoldBackgroundColor,
        appBar: AppBar(
          leadingWidth: 28,
          backgroundColor: CustomTheme.basicTheme.primaryColor,
          /*leading: IconButton(
            icon: const Icon(Icons.arrow_back_ios_new),
            onPressed: () {
              Navigator.pop(context);
            },
          ),*/
          title: const Text(
            'Please Select a Category',
            style: TextStyle(
              fontSize: 27,
              fontWeight: FontWeight.w400,
            ),
          ),
        ),
        body: Center(
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: <Widget>[
              // Vaccination Sites
              ElevatedButton(
                style: basicButton,
                child: const Text('Vaccination Sites'),
                onPressed: () {
                  Navigator.pushNamed(context, '/vaxSites');
                },
              ),
              const SizedBox(height: 50),

              // Test Sites
              ElevatedButton(
                onPressed: () {},
                style: basicButton,
                child: const Text('Testing Sites'),
              ),
              const SizedBox(height: 50),
              // Food Drive
              ElevatedButton(
                style: basicButton,
                onPressed: () {},
                child: const Text('Food Drive'),
              ),
              const SizedBox(height: 50),

              // Town Halls
              ElevatedButton(
                style: basicButton,
                onPressed: () {},
                child: const Text('Town Halls'),
              ),
              const SizedBox(height: 50),
            ],
          ),
        ),
      ),
    );
  }
}
