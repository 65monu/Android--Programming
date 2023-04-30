Q 6-Create a list of all courses in your college and on selecting a particular course teacher-in- charge
of that course should appear at the bottom of the screen.
               Solution 6 :
activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:tools="http://schemas.android.com/tools"
android:orientation="vertical"
android:layout_width="match_parent"
android:layout_height="wrap_content">
<ListView
android:id="@+id/listView"
android:layout_width="match_parent"
android:layout_height="match_parent"
/>
<TextView
android:id="@+id/txtView"
android:layout_width="match_parent"
android:layout_height="wrap_content"
/>
</LinearLayout>
            MainActivity.java
 
package com.example.practical6;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import android.util.Log;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
ListView listView=(ListView)findViewById(R.id.listView);
TextView textView=(TextView)findViewById(R.id.txtView);
String[] listItem = {"BSc","BCom","BA"};
final ArrayAdapter<String> adapter = new
ArrayAdapter<String>(this,android.R.layout.simple_list_item_1,
listItem);
listView.setAdapter(adapter);
listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
@Override
public void onItemClick(AdapterView<?> adapterView, View view, int
position, long l) {
// TODO Auto-generated method stub
String value=adapter.getItem(position);
Log.v("value",value);
String teacher="";
if(value.equals("BSc")) { teacher="abc"; }
else if(value.equals("BCom")){ teacher="pqr"; }
else if(value.equals("BA")) teacher="ghj";
Toast.makeText(getApplicationContext(),teacher,Toast.LENGTH_SHORT).show();
}
});
}
}
 
Q7 :Create an application with three option buttons, on selecting a button color of the screen will
change.
       Solution 7 :
activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout
xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:tools="http://schemas.android.com/tools"
android:id="@+id/rlVar1"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:background="@color/colorAccent"
tools:context=".MainActivity">
<TextView
android:id="@+id/tvVar1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_centerHorizontal="true"
android:layout_marginTop="240dp"
android:text="What would you like?"
android:textSize="25dp"
android:textStyle="bold" />
<LinearLayout
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@+id/tvVar1"
android:layout_centerInParent="true"
android:layout_marginTop="60dp"
android:orientation="horizontal"
android:padding="10dp">
<Button
android:id="@+id/btVar1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:background="#0EA1E3"
android:padding="20dp"
android:text="Cool"
android:textColor="#303F9F"
android:textSize="20dp" />
<Button
android:id="@+id/btVar2"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:background="#F6F6F6"
android:padding="20dp"
android:text="neutral"
android:textColor="#1A237E"
android:textSize="20dp" />
<Button
android:id="@+id/btVar3"
android:layout_width="150dp"
android:layout_height="wrap_content"
android:background="#FD0505"
android:padding="20dp"
android:text="Hot"
android:textColor="#311B92"
android:textSize="20dp" />
</LinearLayout>
</RelativeLayout>
           Main_Activity.java

package com.example.practical_7;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
Button button1, button2 , button3;
final RelativeLayout relativeLayout;
// set button 1 with its id
button1 = findViewById(R.id.btVar1);
// set button 2 with its id
button2 = findViewById(R.id.btVar2);
// set button 2 with its id
button3 = findViewById(R.id.btVar3);
// set relative layout with its id
relativeLayout = findViewById(R.id.rlVar1);
// onClick function for button 1
button1.setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View view) {
// set the color to relative layout
relativeLayout.setBackgroundResource(R.color.cool);
}
});
// onClick function for button 2
button2.setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View view) {
// set the color to relative layout
relativeLayout.setBackgroundResource(R.color.neutral);
}
});
button3.setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View view){
// set the color to relative layout
relativeLayout.setBackgroundResource(R.color.hot);
}
}
);
}
}
colors.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<resources>
<color name="purple_200">#FFBB86FC</color>
<color name="purple_500">#FF6200EE</color>
<color name="purple_700">#FF3700B3</color>
<color name="teal_200">#FF03DAC5</color>
<color name="teal_700">#FF018786</color>
<color name="black">#FF000000</color>
<color name="white">#FFFFFFFF</color>
<color name="colorPrimary">#6200EE</color>
<color name="colorPrimaryDark">#3700B3</color>
<color name="colorAccent">#03DAC5</color>
<color name="blue">#2196F3</color>
<color name="cool">#188FCF</color>
<color name="neutral">#F0EFED</color>
<color name="hot">#EC0909</color>
</resources>
 
Q 8 :Create an application to display various activity life cycle and fragment lifecycle methods.
                Solution 8 :
activity_main.xml
 
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
tools:context=".MainActivity">
<TextView
android:id="@+id/tv1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginStart="10dp"
android:layout_marginTop="30dp"
android:text="@string/activity_lifecycle"
android:textSize="20sp"
android:textStyle="bold" />
<TextView
android:id="@+id/result1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginStart="30dp"
android:layout_marginTop="60dp"
android:text=" "
android:textSize="20sp"
android:textStyle="bold" />
<fragment
android:id="@+id/frag"
android:name="com.example.practical8.BlankFragment"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginStart="10dp"
android:layout_marginTop="30dp"
android:layout_toEndOf="@+id/tv1" />
</RelativeLayout>
fragment_blank.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
tools:context=".BlankFragment">
<!-- TODO: Update blank fragment layout -->
<TextView
android:id="@+id/tv"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginTop="0dp"
android:text="@string/fragment_lifecycle"
android:textSize="20sp"
android:textStyle="bold" />
<TextView
android:id="@+id/result1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@id/tv"
android:layout_marginTop="0dp"
android:text=" "
android:textSize="20sp"
android:textStyle="bold" />
</RelativeLayout>
           MainActivity.java
 
package com.example.practical8;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
TextView result;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
result = findViewById(R.id.result1);
result.setText("onCreate");
}
@Override
protected void onStop() {
super.onStop();
String res = result.getText().toString();
result.setText(res + "\n" + "onStart");
}
@Override
protected void onStart() {
super.onStart();
String res = result.getText().toString();
result.setText(res + "\n" + "onStart");
}
@Override
protected void onPause() {
super.onPause();
String res = result.getText().toString();
result.setText(res + "\n" + "onPause");
}
protected void onResume() {
super.onResume();
String res = result.getText().toString();
result.setText(res + "\n" + "onResume");
}
@Override
protected void onDestroy() {
super.onDestroy();
String res = result.getText().toString();
result.setText(res + "\n" + "onDestroy");
}
}
BlankFragment.java
 
package com.example.practical8;
import android.os.Bundle;
import androidx.fragment.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
public class BlankFragment extends Fragment {
TextView result;
@Override
public View onCreateView(LayoutInflater inflater, ViewGroup container,
Bundle savedInstanceState) {
// Inflate the layout for this fragment
View view = inflater.inflate(R.layout.fragment_blank, container,
false);
result = (TextView) view.findViewById(R.id.result1);
return view;
}
@Override
public void onStop() {
super.onStop();
String res = result.getText().toString();
result.setText(res + "\n" + "onStop");
}
@Override
public void onResume() {
super.onResume();
String res = result.getText().toString();
result.setText(res + "\n" + "onResume");
}
@Override
public void onPause() {
super.onPause();
String res = result.getText().toString();
result.setText(res + "\n" + "onPause");
}
@Override
public void onStart() {
super.onStart();
String res = result.getText().toString();
result.setText(res + "\n" + "onStart");
}
}
strings.xml
<!--Created by - MONU NNNN -->
<resources>
<string name="app_name">practical8</string>
<string name="activity_lifecycle">"Activity Lifecycle</string>
<string name="fragment_lifecycle">"Fragment Lifecycle</string>
</resources>
 
Q 9 :Create an application with 2 fragments, one to set the background and other to set the fore-color
of the text.
                    Solution 9 :
activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:id="@+id/main_layout"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:orientation="vertical">
<TextView
android:id="@+id/textview"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_centerHorizontal="true"
android:layout_marginLeft="100dp"
android:layout_marginTop="10dp"
android:text="FRAGMENT EXAMPLE APP"
android:textColor="@color/black" />
<fragment
android:id="@+id/frag1"
android:name="com.example.practical9.BGColor"
android:layout_width="match_parent"
android:layout_height="0dp"
android:layout_weight="2" />
<fragment
android:id="@+id/frag2"
android:name="com.example.practical9.FGColor"
android:layout_width="match_parent"
android:layout_height="0dp"
android:layout_weight="2" />
</LinearLayout>
                MainActivity.java
 
package com.example.practical9;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
TextView tv1;
TextView tv2;
TextView tv3;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
tv1 = (TextView) findViewById(R.id.textview);
tv2 = (TextView) findViewById(R.id.textview2);
tv3 = (TextView) findViewById(R.id.textview3);
LinearLayout ll = (LinearLayout) findViewById(R.id.main_layout);
RadioGroup rg = (RadioGroup) findViewById(R.id.bg_radiogroup);
rg.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
@Override
public void onCheckedChanged(RadioGroup radioGroup, int checkedId) {
RadioButton checkedRadioButton = (RadioButton)
radioGroup.findViewById(checkedId);
boolean isChecked = checkedRadioButton.isChecked();
if (isChecked) {
switch (checkedRadioButton.getId()) {
case R.id.radioButton1:
ll.setBackgroundColor(getResources().getColor(R.color.purple_500));
break;
case R.id.radioButton2:
ll.setBackgroundColor(getResources().getColor(R.color.teal_200));
break;
case R.id.radioButton3:
ll.setBackgroundColor(getResources().getColor(R.color.yellow));
break;
case R.id.radioButton4:
ll.setBackgroundColor(getResources().getColor(R.color.green));
break;
case R.id.radioButton5:
ll.setBackgroundColor(getResources().getColor(R.color.Red));
break;
}
}
}
});
RadioGroup rg2 = (RadioGroup) findViewById(R.id.fg_radiogroup);
rg2.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
@Override
public void onCheckedChanged(RadioGroup radioGroup, int checkedId) {
RadioButton checkedRadioButton = (RadioButton)
radioGroup.findViewById(checkedId);
boolean isChecked = checkedRadioButton.isChecked();
if (isChecked) {
switch (checkedRadioButton.getId()) {
case R.id.rb1:
tv1.setTextColor(getResources().getColor(R.color.green));
tv2.setTextColor(getResources().getColor(R.color.green));
tv3.setTextColor(getResources().getColor(R.color.green));
break;
case R.id.rb2:
tv1.setTextColor(getResources().getColor(R.color.purple_700));
tv2.setTextColor(getResources().getColor(R.color.purple_700));
tv3.setTextColor(getResources().getColor(R.color.purple_700));
break;
case R.id.rb3:
tv1.setTextColor(getResources().getColor(R.color.yellow));
tv2.setTextColor(getResources().getColor(R.color.yellow));
tv3.setTextColor(getResources().getColor(R.color.yellow));
break;
case R.id.rb4:
tv1.setTextColor(getResources().getColor(R.color.white));
tv2.setTextColor(getResources().getColor(R.color.white));
tv3.setTextColor(getResources().getColor(R.color.white));
break;
case R.id.rb5:
tv1.setTextColor(getResources().getColor(R.color.Red));
tv2.setTextColor(getResources().getColor(R.color.Red));
tv3.setTextColor(getResources().getColor(R.color.Red));
break;
}
}
}
});
}
}
fragment_bg_color.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:orientation="vertical">
<TextView
android:id="@+id/textview2"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_centerHorizontal="true"
android:layout_gravity="center_horizontal"
android:layout_marginTop="15dp"
android:text="SELECT BACKGROUND COLOUR"
android:textAlignment="center"
android:textColor="@color/black"
android:textSize="15sp"
android:textStyle="bold" />
<RadioGroup
android:id="@+id/bg_radiogroup"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:orientation="vertical">
<RadioButton
android:id="@+id/radioButton1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:text="Purple" />
<RadioButton
android:id="@+id/radioButton2"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Teal" />
<RadioButton
android:id="@+id/radioButton3"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Yellow" />
<RadioButton
android:id="@+id/radioButton4"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Green" />
<RadioButton
android:id="@+id/radioButton5"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Red" />
</RadioGroup>
</LinearLayout>
BGColor.java
//Created by - MONU NNNN
package com.example.practical9;
import android.os.Bundle;
import androidx.fragment.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
public class BGColor extends Fragment {
@Override
public View onCreateView(LayoutInflater inflater, ViewGroup container,
Bundle savedInstanceState) {
return inflater.inflate(R.layout.fragment_bg_color,
container, false);
}
}
fragment_fg_color.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:orientation="vertical">
<TextView
android:id="@+id/textview3"
android:layout_width="397dp"
android:layout_height="50dp"
android:layout_gravity="center_horizontal"
android:text="CHANGE TEXT COLOUR"
android:textAlignment="center"
android:textColor="@color/black"
android:textStyle="bold" />
<RadioGroup
android:id="@+id/fg_radiogroup"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:orientation="vertical">
<RadioButton
android:id="@+id/rb1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Green" />
<RadioButton
android:id="@+id/rb2"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:text="Purple" />
<RadioButton
android:id="@+id/rb3"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Yellow" />
<RadioButton
android:id="@+id/rb4"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="White" />
<RadioButton
android:id="@+id/rb5"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_weight="0"
android:text="Red" />
</RadioGroup>
</LinearLayout>
FGColor.java
//Created by - MONU NNNN
package com.example.practical9;
import android.os.Bundle;
import androidx.fragment.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
public class FGColor extends Fragment {
@Override
public View onCreateView(LayoutInflater inflater, ViewGroup container,
Bundle savedInstanceState) {
return inflater.inflate(R.layout.fragment_fg_color,
container, false);
}
}
colors.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<resources>
<color name="purple_200">#FFBB86FC</color>
<color name="purple_500">#FF6200EE</color>
<color name="purple_700">#FF3700B3</color>
<color name="teal_200">#FF03DAC5</color>
<color name="teal_700">#FF018786</color>
<color name="black">#FF000000</color>
<color name="white">#FFFFFFFF</color>
<color name="yellow">#FFFFFF00</color>
<color name="magenta">#FFFF00FF</color>
<color name="Red"> #ff0000</color>
<color name="green">#7fff00 </color>
<color name="blue">#ADD8E6</color>
</resources>
strings.xml
<!--Created by - MONU NNNN -->
<resources>
<string name="app_name">Question_9</string>
<!-- TODO: Remove or change this placeholder text -->
<string name="hello_blank_fragment">Hello blank fragment</string>
</resources>
 
