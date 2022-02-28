import 'package:flutter/material.dart';
import 'package:macbook_el_monte/themes/custom_theme.dart';

class TestSites extends StatelessWidget {
  const TestSites({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: CustomTheme.basicTheme.scaffoldBackgroundColor,
        drawer: Drawer(
          backgroundColor: const Color.fromARGB(255, 47, 49, 54),
          child: ListView(
            // Important: Remove any padding from the ListView
            padding: EdgeInsets.zero,
            children: [
              const SizedBox(height: 100),

              // Vax Sites Tile
              ListTile(
                title: const Text('Vaccination Sites', style: nonselectedTile),
                onTap: () {
                  Navigator.pushNamed(context, '/vaxSites');
                },
              ),
              drawerDivider,
              // Test Sites Tile
              ListTile(
                title: const Text('Test Sites', style: selectedTile),
                onTap: () {
                  Navigator.pushNamed(context, '/testSites');
                },
              ),
              drawerDivider,
              // Food Drive
              ListTile(
                title: const Text('Food Drive', style: nonselectedTile),
                onTap: () {},
              ),
              drawerDivider,
              // Town Halls
              ListTile(
                  title: const Text('Town Halls', style: nonselectedTile),
                  onTap: () {}),
              drawerDivider,
            ],
          ),
        ),
        appBar: AppBar(
          title: const Text('COVID-19 Test Sites',
              style: TextStyle(
                fontSize: 24,
                fontWeight: FontWeight.w400,
              )),
          backgroundColor: CustomTheme.basicTheme.primaryColor,
          //leading // insert the drawer function to avoid back button
          // Maybe approach the page w/o scaffold -- review blueprint for layout
        ),
      ),
    );
  }
}
