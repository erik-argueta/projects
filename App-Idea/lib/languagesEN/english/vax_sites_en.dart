import 'package:flutter/material.dart';
import 'package:windows_el_monte/themes/custom_theme.dart';

class VaccinationSites extends StatelessWidget {
  const VaccinationSites({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    const TextStyle drawerStyle = TextStyle(
      fontSize: 27,
      color: Color.fromARGB(255, 135, 139, 144),
      fontWeight: FontWeight.w400,
    );

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
                title: const Text(
                  'Vaccination Sites',
                  style: TextStyle(
                      color: Color.fromARGB(255, 247, 247, 247),
                      fontSize: 27,
                      fontWeight: FontWeight.w400),
                ),
                selectedColor: const Color.fromARGB(255, 56, 60, 65),
                selected: true,
                onTap: () {},
              ),

              // Test Sites Tile
              ListTile(
                title: const Text('Test Sites', style: drawerStyle),
                onTap: () {},
              ),

              // Food Drive
              ListTile(
                title: const Text('Food Drive', style: drawerStyle),
                onTap: () {},
              ),

              // Town Halls
              ListTile(
                  title: const Text('Town Halls', style: drawerStyle),
                  onTap: () {}),
            ],
          ),
        ),
        appBar: AppBar(
          title: const Text('Vaccination Sites',
              style: TextStyle(
                fontSize: 27,
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
