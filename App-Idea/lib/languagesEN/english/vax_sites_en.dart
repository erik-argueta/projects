import 'package:flutter/material.dart';
import 'package:windows_el_monte/themes/custom_theme.dart';

class VaccinationSites extends StatelessWidget {
  const VaccinationSites({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: CustomTheme.basicTheme.scaffoldBackgroundColor,
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
