Q10 :Create an application with an activity having EditText and a button (with name “Send”). On clicking
the Send button, make use of implicit intent that uses a Send Action and let the user select the
app from app chooser and navigate to that application.
            Solution 10 :
activity_main.xml
<!--Created by - MONU NNNN -->
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
android:paddingLeft="@dimen/activity_horizontal_margin"
android:paddingTop="@dimen/activity_vertical_margin"
android:paddingRight="@dimen/activity_horizontal_margin"
android:paddingBottom="@dimen/activity_vertical_margin"
tools:context=".MainActivity">
<EditText
android:id="@+id/editText1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignParentTop="true"
android:layout_alignParentRight="true"
android:layout_marginTop="80dp"
android:layout_marginRight="80dp"
android:layout_marginLeft="25dp"
android:ems="10">
<requestFocus />
</EditText>
<EditText
android:id="@+id/editText2"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@+id/editText1"
android:layout_alignLeft="@+id/editText1"
android:layout_marginLeft="0dp"
android:layout_marginTop="20dp"
android:ems="10">
<requestFocus />
</EditText>
<EditText
android:id="@+id/editText3"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@+id/editText2"
android:layout_alignLeft="@+id/editText2"
android:layout_marginTop="20dp"
android:ems="10"
android:inputType="textMultiLine" />
<TextView
android:id="@+id/textView1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignBaseline="@+id/editText1"
android:layout_alignBottom="@+id/editText1"
android:layout_marginHorizontal="30dp"
android:layout_marginBottom="15dp"
android:text="To :" />
<TextView
android:id="@+id/textView2"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignBaseline="@+id/editText2"
android:layout_alignBottom="@+id/editText2"
android:layout_marginHorizontal="30dp"
android:layout_marginBottom="15dp"
android:text="Subject :" />
<TextView
android:id="@+id/textView3"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignBaseline="@+id/editText3"
android:layout_alignBottom="@+id/editText3"
android:layout_alignParentLeft="true"
android:layout_marginHorizontal="30dp"
android:layout_marginBottom="15dp"
android:text="Message:" />
<Button
android:id="@+id/button1"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_below="@+id/editText3"
android:layout_centerHorizontal="true"
android:layout_marginTop="20dp"
android:layout_marginHorizontal="30dp"
android:layout_marginBottom="15dp"
android:text="Send" />
</RelativeLayout>
MainActivity.java
//Created by - MONU NNNN
package com.example.practical10;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
public class MainActivity extends Activity {
EditText editTextTo,editTextSubject,editTextMessage;
Button send;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
editTextTo=(EditText)findViewById(R.id.editText1);
editTextSubject=(EditText)findViewById(R.id.editText2);
editTextMessage=(EditText)findViewById(R.id.editText3);
send=(Button)findViewById(R.id.button1);
send.setOnClickListener(new View.OnClickListener(){
@Override
public void onClick(View arg0) {
String to=editTextTo.getText().toString();
String subject=editTextSubject.getText().toString();
String message=editTextMessage.getText().toString();
Intent email = new Intent(Intent.ACTION_SEND);
email.putExtra(Intent.EXTRA_EMAIL, new String[]{ to});
email.putExtra(Intent.EXTRA_SUBJECT, subject);
email.putExtra(Intent.EXTRA_TEXT, message);
email.setType("message/rfc822");
startActivity(Intent.createChooser(email, "Choose an Email client
:"));
}
});
}
@Override
public boolean onCreateOptionsMenu(Menu menu) {
getMenuInflater().inflate(R.menu.menus_main, menu);
return true;
}
@Override
public boolean onOptionsItemSelected(MenuItem item) {
int id = item.getItemId();
if (id == R.id.action_settings) {
return true;
}
return super.onOptionsItemSelected(item);
}
}
dimens.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<resources>
<dimen name="activity_horizontal_margin">10dp</dimen>
<dimen name="activity_vertical_margin">10dp</dimen>
</resources>
menus_main.xml
<!--Created by - MONU NNNN -->
<menu xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
tools:context="net.XXX.YYY.ZZZZ">
<item
android:id="@+id/action_settings"
android:orderInCategory="100"
android:title="@string/action_settings"
app:showAsAction="never" />
</menu>
strings.xml
<!--Created by - MONU NNNN -->
<resources>
<string name="app_name">practical10</string>
<string name="action_settings">"Action settings</string>
</resources>
 
Question 11 :Create a Login application. On successful login, use explicit intent to second activity displaying
welcome message (Welcome Username) to the user and a logout button. When user presses the
logout button, a dialog box with a message (“Are you sure you want to exit?”) and two buttons
(“Yes” and “No”) should appear to confirm logout. On “Yes” button click, go to login activity and on
“No”, stay on the same activity
           Solution 11 :
activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="251dp"
android:layout_height="567dp"
android:orientation="vertical"
>
<TextView
android:id="@+id/textViewCounter"
android:layout_width="match_parent"
android:layout_height="55dp"
android:text="@string/login" />
<EditText
android:id="@+id/editLogin"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:ems="10"
/>
<TextView
android:id="@+id/textViewCounter2"
android:layout_width="match_parent"
android:layout_height="55dp"
android:text="@string/password"
/>
<EditText
android:id="@+id/editPassword"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:ems="10"
/>
<Button
android:id="@+id/buttonSubmit"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:text="@string/submit" />
</LinearLayout>
Main_activity.java
//Created by - MONU NNNN
package com.example.practical11;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.appcompat.app.AppCompatActivity;
import android.util.Log;
import android.widget.Toast;
import android.content.Intent;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
Button b1 = (Button) this.findViewById(R.id.buttonSubmit);
EditText e1 = (EditText) findViewById(R.id.editLogin);
EditText e2 = (EditText) findViewById(R.id.editPassword);
Intent i = new Intent(this, Second_activity.class);
b1.setOnClickListener(new Button.OnClickListener() {
public void onClick(View v) {
String text1 = e1.getText().toString();
String text2 = e2.getText().toString();
Log.v(text1, "login");
Log.v(text2, "password");
if (text1.equals("login") && text2.equals("password")) {
Toast.makeText(MainActivity.this, "Successful",
Toast.LENGTH_SHORT).show();
startActivity(i);
} else {
Toast.makeText(MainActivity.this, "Unsuccessful",
Toast.LENGTH_SHORT).show();
}
}
});
}
}
activity_second.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="251dp"
android:layout_height="567dp"
android:orientation="vertical"
>
<TextView
android:id="@+id/textViewCounter"
android:layout_width="match_parent"
android:layout_height="55dp"
android:text="@string/WelcomeUser" />
<Button
android:id="@+id/button2"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:text="@string/logout" />
</LinearLayout>
AndroidManifest.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
package="com.example.practical11">
<application
android:allowBackup="true"
android:icon="@mipmap/ic_launcher"
android:label="@string/app_name"
android:roundIcon="@mipmap/ic_launcher_round"
android:supportsRtl="true"
android:theme="@style/Theme.Practical11">
<activity
android:name=".AndroidManifest"
android:exported="false" />
<activity
android:name=".Second_activity"
android:exported="false" />
<activity
android:name=".MainActivity"
android:exported="true">
<intent-filter>
<action android:name="android.intent.action.MAIN" />
<category android:name="android.intent.category.LAUNCHER" />
</intent-filter>
</activity>
</application>
</manifest>
Second_activity.java
//Created by - MONU NNNN
package com.example.practical11;
import android.os.Bundle;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.app.AlertDialog;
import android.content.DialogInterface;
public class Second_activity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_second);
Button b11 = (Button) this.findViewById(R.id.button2);
Intent k = new Intent(this, MainActivity.class);
AlertDialog.Builder ad = new AlertDialog.Builder(this);
b11.setOnClickListener(v -> {
ad.setTitle("Login App");
ad.setMessage("Do you want to logout");
ad.setNegativeButton("Yes", new DialogInterface.OnClickListener() {
public void onClick(DialogInterface Dialog, int buttonID) {
startActivity(k);
return;
}
});
ad.setPositiveButton("No", new
DialogInterface.OnClickListener() {
public void onClick(DialogInterface Dialog, int buttonID) {
return;
}
});
ad.show();
});
}
}
 
Question 12 :Create an application for Broadcast sender and receivers.
          Solution 12 :
BroadcastSender activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
tools:context=".MainActivity">
<Button
android:id="@+id/button"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:text="Send Broadcast Message"
android:onClick="onBroadcastSendBtnClicked"
app:layout_constraintBottom_toBottomOf="parent"
app:layout_constraintEnd_toEndOf="parent"
app:layout_constraintStart_toStartOf="parent"
app:layout_constraintTop_toTopOf="parent"/>
</androidx.constraintlayout.widget.ConstraintLayout>
BroadcastSender MainActivity.java
//Created by - MONU NNNN
package com.example.practical12;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
}
public void onBroadcastSendBtnClicked(View v){
Intent intent = new Intent();
intent.setAction("com.practical12.myBroadcastMessage");
intent.setFlags(Intent.FLAG_INCLUDE_STOPPED_PACKAGES);
sendBroadcast(intent);
}
}
BroadcastReceiver activity_main.xml
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
android:text="Broadcasting custom intents"
app:layout_constraintBottom_toBottomOf="parent"
app:layout_constraintEnd_toEndOf="parent"
app:layout_constraintStart_toStartOf="parent"
app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>
BroadcastReceiver MyBroadcastReceiver.java
//Created by - MONU NNNN
package com.example.practical12_broadcastreceiver;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;
public class MyBroadcastReceiver extends BroadcastReceiver {
@Override
public void onReceive(Context context, Intent intent) {
Log.i("BroadcastReceiver", "Broadcast message is received");
Toast.makeText(context,"Broadcast message is received",
Toast.LENGTH_LONG).show();
}
}
BroadcastReceiver AndroidManifest.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:tools="http://schemas.android.com/tools">
<application
android:allowBackup="true"
android:dataExtractionRules="@xml/data_extraction_rules"
android:fullBackupContent="@xml/backup_rules"
android:icon="@mipmap/ic_launcher"
android:label="@string/app_name"
android:supportsRtl="true"
android:theme="@style/Theme.Practical12_BroadcastReceiver"
tools:targetApi="31">
<receiver
android:name=".MyBroadcastReceiver"
android:enabled="true"
android:exported="true">
<intent-filter>
<action android:name = "com.practical12.myBroadcastMessage"></action>
</intent-filter>
</receiver>
<activity
android:name=".MainActivity"
android:exported="true">
<intent-filter>
<action android:name="android.intent.action.MAIN" />
<category android:name="android.intent.category.LAUNCHER" />
</intent-filter>
</activity>
</application>
</manifest>
MainActivity.java
//Created by - MONU NNNN
package com.example.practical12_broadcastreceiver;
import androidx.appcompat.app.AppCompatActivity;
import android.content.IntentFilter;
import android.os.Bundle;
public class MainActivity extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
IntentFilter intentFilter = new
IntentFilter("com.practical12.myBroadcastMessage");
MyBroadcastReceiver objReceiver = new MyBroadcastReceiver();
registerReceiver(objReceiver,intentFilter);
}
}

