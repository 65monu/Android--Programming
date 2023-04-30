 Q 1 :Create a “Hello World” application. That will display “Hello World” in the middle of the screen in the
emulator. Also display “Hello World” in the middle of the screen in the Android Phone.
Solution 1 :

activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
tools:context=".MainActivity">
<TextView
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:text="Hello World!"
app:layout_constraintBottom_toBottomOf="parent"
app:layout_constraintEnd_toEndOf="parent"
app:layout_constraintStart_toStartOf="parent"
app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>
              MainActivity.java

package com.example.practical1;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
}
}
 
Q 2:Create an application with three buttons (increment, decrement and reset) and a textView aligned
vertically. On clicking, increment/decrement button, the value of the textview should
increment/decrement by 1 while selecting the reset button, the value of textview should become
zero.
                     Solution 2 :
activity_main.xml :
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:background="#9C27B0"
android:backgroundTintMode="screen"
tools:context=".MainActivity">
<LinearLayout
android:id="@+id/linearLayout"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:orientation="horizontal"
app:layout_constraintBottom_toBottomOf="parent"
app:layout_constraintEnd_toEndOf="parent"
app:layout_constraintHorizontal_bias="0.497"
app:layout_constraintStart_toStartOf="parent"
app:layout_constraintTop_toTopOf="parent"
app:layout_constraintVertical_bias="0.157">
<Button
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginLeft="8dp"
android:onClick="decrement"
android:padding="16dp"
android:text="-"
android:textSize="24sp"
android:textStyle="bold"
/>
<TextView
android:id="@+id/quantity_text_view"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginLeft="8dp"
android:layout_marginRight="8dp"
android:fontFamily="sans-serif-condensed-medium"
android:padding="16dp"
android:text="0"
android:textColor="@color/black"
android:textSize="16sp"
android:textStyle="italic" />
<Button
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:onClick="increment"
android:padding="16dp"
android:text="+"
android:textSize="24sp"
/>
</LinearLayout>
<Button
android:id="@+id/reset"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginTop="108dp"
android:onClick="reset"
android:text="Reset"
android:textSize="24sp"
android:textStyle="bold|italic"
app:layout_constraintEnd_toEndOf="@+id/linearLayout"
app:layout_constraintHorizontal_bias="0.503"
app:layout_constraintStart_toStartOf="@+id/linearLayout"
app:layout_constraintTop_toBottomOf="@+id/linearLayout" />
</androidx.constraintlayout.widget.ConstraintLayout>
               MainActivity.java
package com.example.Practical_2;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
private TextView mytext;
private int number =0;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
mytext = findViewById(R.id.quantity_text_view);
}
public void decrement(View view) {
if (number !=0)
{
number-=1;
}
DisplayOnText(number);
}
public void increment(View view) {
number+=1;
DisplayOnText(number);
}
public void reset(View view) {
number =0;
DisplayOnText(number);
}
public void DisplayOnText(int num)
{
mytext.setText(""+num);
}
}
Output 2 :
Q 3 :Create an application with a login module. (Check username and password).
           Solution 3 :
activity_main.xml
 
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="match_parent"
android:layout_height="match_parent"
>
<TextView
android:id="@+id/tvName"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginStart="21dp"
android:layout_marginTop="49dp"
android:text="User Name"
android:textSize="18sp" />
<EditText
android:id="@+id/etUsername"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignBaseline="@+id/tvName"
android:layout_alignBottom="@+id/tvName"
android:layout_alignParentEnd="true"
android:layout_marginEnd="23dp"
android:ems="10"
android:inputType="textPersonName" />
<TextView
android:id="@+id/tvPass"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignEnd="@+id/tvName"
android:layout_below="@+id/etUsername"
android:layout_marginTop="32dp"
android:text="Password"
android:textSize="18sp" />
<EditText
android:id="@+id/etPassword"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignBaseline="@+id/tvPass"
android:layout_alignBottom="@+id/tvPass"
android:layout_alignStart="@+id/etUsername"
android:ems="10"
android:inputType="textPassword" />
<Button
android:id="@+id/button"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@+id/etPassword"
android:layout_centerHorizontal="true"
android:layout_marginTop="38dp"
android:text="LOGIN"
/>
<TextView
android:id="@+id/tvLoginStatus"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@id/button"
android:layout_centerHorizontal="true"
android:layout_marginTop="100sp"
/>
</RelativeLayout>
               Main_activity.java
 
package com.example.practical_3;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
EditText etUsername, etPassword;
Button btnStatus;
TextView tvLoginStatus;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
etUsername = (EditText) findViewById(R.id.etUsername);
etPassword = (EditText) findViewById(R.id.etPassword);
btnStatus = (Button) findViewById(R.id.button);
tvLoginStatus = (TextView) findViewById(R.id.tvLoginStatus);
btnStatus.setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View v) {
check();
}
});
}
public void check(){
if(etUsername.getText().toString().equals("login") &&
etPassword.getText().toString().equals("password")){
tvLoginStatus.setText("Login successful");
}else{
Toast.makeText(this, "Login failed", Toast.LENGTH_LONG).show();
}
}
}
 
          Question 4 :
Create spinner with strings taken from resource folder (res >> value folder) and on changing the
spinner value, Image will change.
Solution 4 :
activity_main.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:visibility="visible"
android:orientation="vertical">
<TextView
android:id="@+id/text1"
android:layout_width="wrap_content"
android:layout_height="116dp"
android:layout_weight="1"
android:text="TextView" />
<ImageView
android:id="@+id/img1"
android:layout_width="wrap_content"
android:layout_height="116dp"
android:layout_weight="1"
android:text="TextView" />
<Spinner
android:id="@+id/spinner1"
android:layout_width="wrap_content"
android:layout_height="116dp"
android:layout_weight="1"
android:text="TextView" />
</LinearLayout>
            MainActivity.java
 
package com.example.practical4;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Spinner;
import android.widget.ImageView;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.view.View;
import android.widget.AdapterView.OnItemSelectedListener;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
TextView text1 = (TextView) findViewById(R.id.text1);
ImageView img1 = (ImageView) findViewById(R.id.img1);
String[] city = {"delhi","mumbai","chennai","kolkata"};
Spinner spin = (Spinner) findViewById(R.id.spinner1);
ArrayAdapter<String> arrayadpt = new
ArrayAdapter<String>(this,android.R.layout.simple_spinner_item, city);
spin.setAdapter(arrayadpt);
spin.setOnItemSelectedListener(new OnItemSelectedListener() {
public void onItemSelected(AdapterView<?> parent, View v, int
position,long id){
text1.setText("Your selected city : "+ city[position]);
if(position==0) {img1.setImageResource(R.drawable.img2); }
else if(position==1) {img1.setImageResource(R.drawable.img2); }
else if(position==2) {img1.setImageResource(R.drawable.img3); }
else if(position==3) {img1.setImageResource(R.drawable.img4); }
}
public void onNothingSelected(AdapterView<?> parent){
text1.setText("");
}
});
}
}
 
Q  :Create a menu with some options and selected options should appear in the text box.
Solution 5 :
activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:background="#4593B5"
tools:context=".MainActivity">
<TextView
android:id="@+id/mytv"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:text="Welcome!"
android:textSize="32sp"
android:textStyle="bold"
app:layout_constraintBottom_toBottomOf="parent"
app:layout_constraintLeft_toLeftOf="parent"
app:layout_constraintRight_toRightOf="parent"
app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>
Menus.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:android="http://schemas.android.com/apk/res/android">
<item
android:id="@+id/id1"
android:title="Option1" />
<item
android:id="@+id/id2"
android:title="Option2" />
<item
android:id="@+id/id3"
android:title="Option3" />
<item
android:id="@+id/id4"
android:title="Option4" />
<item
android:id="@+id/id5"
android:title="Option5" />
</menu>
    MainActivity.java
 
package com.example.practical_5;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
TextView tv;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
tv = findViewById(R.id.mytv);
}
@Override
public boolean onCreateOptionsMenu(Menu menu) {
MenuInflater m = getMenuInflater();
m.inflate(R.menu.menus, menu);
return true;
}
@Override
public boolean onOptionsItemSelected( MenuItem item) {
switch (item.getItemId())
{
case R.id.id1:
Toast.makeText(this, "Option1", Toast.LENGTH_SHORT).show();
tv.setText("Option1");
break;
case R.id.id2:
Toast.makeText(this, "Option2", Toast.LENGTH_SHORT).show();
tv.setText("Option2");
break;
case R.id.id3:
Toast.makeText(this, "Option3", Toast.LENGTH_SHORT).show();
tv.setText("Option3");
break;
case R.id.id4:
Toast.makeText(this, "Option4", Toast.LENGTH_SHORT).show();
tv.setText("Option4");
case R.id.id5:
Toast.makeText(this, "Option5", Toast.LENGTH_SHORT).show();
tv.setText("Option5");
break;
}
return true;
}
}
 
