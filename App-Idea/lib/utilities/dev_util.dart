import 'package:flutter/material.dart';
import 'package:macbook_el_monte/themes/custom_theme.dart';

/*
  - Look into whitening the already selected tile and implement to the other pages
*/

Widget navDrawer(String label1, String label2, String label3, String label4) {
  return Drawer(
    backgroundColor: CustomTheme.basicTheme.backgroundColor,
    child: ListView(
      padding: EdgeInsets.zero,
      children: [
        const SizedBox(height: 100),
        ListTile(
          title: Text(label1, style: selectedTile),
          onTap: () { },
        ),
        drawerDivider,

        ListTile(
          title: Text(label2, style: selectedTile),
          onTap: () {},
        ),
        drawerDivider,

        ListTile(
          title: Text(label3, style: selectedTile),
          onTap: () {},
        ),
        drawerDivider,

        ListTile(
          title: Text(label4, style: selectedTile),
          onTap: () {},
        ),
        drawerDivider,
      ],
    ),
  );
}
