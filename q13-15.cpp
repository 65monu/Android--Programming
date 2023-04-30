Q 13 :Create an application to create a notification having icon, text and title.
               Solution 13 :
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
<Button
android:id="@+id/notifyBtn"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:text="Get notification"
app:layout_constraintBottom_toBottomOf="parent"
app:layout_constraintEnd_toEndOf="parent"
app:layout_constraintStart_toStartOf="parent"
app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>l?
                    MainActivity.java
//Created by - MONU NNNN
package com.example.practical13;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
public class MainActivity extends AppCompatActivity {
Button notifyBtn;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
notifyBtn = findViewById(R.id.notifyBtn);
if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
NotificationChannel channel = new NotificationChannel("NyNotification",
"NyNotification", NotificationManager.IMPORTANCE_DEFAULT);
NotificationManager manager =
getSystemService(NotificationManager.class);
manager.createNotificationChannel(channel);
}
notifyBtn.setOnClickListener(new View.OnClickListener() {
@Override
public void onClick(View view) {
NotificationCompat.Builder builder = new
NotificationCompat.Builder(MainActivity.this, "NyNotification");
builder.setContentTitle("Sample title");
builder.setContentText("This is sample text for Practical 13");
builder.setSmallIcon(R.drawable.notification_icon);
builder.setAutoCancel(true);
NotificationManagerCompat managerCompat =
NotificationManagerCompat.from(MainActivity.this);
if (ActivityCompat.checkSelfPermission(MainActivity.this,
android.Manifest.permission.POST_NOTIFICATIONS) !=
PackageManager.PERMISSION_GRANTED) {
return;
}
managerCompat.notify(1, builder.build());
}
});
}
}
 
Question 14 :Create an application to create services.
             Solution 14 :
activity_main.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
tools:context=".MainActivity">
<Button
android:id="@+id/buttonStart"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignParentTop="true"
android:layout_centerHorizontal="true"
android:layout_marginTop="74dp"
android:text="Start Service" />
<Button
android:id="@+id/buttonStop"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_centerHorizontal="true"
android:layout_centerVertical="true"
android:text="Stop Service" />
<Button
android:id="@+id/buttonNext"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_alignParentBottom="true"
android:layout_centerHorizontal="true"
android:layout_marginBottom="63dp"
android:text="Next Page" />
</RelativeLayout>
                    MainActivity.java
/ 
package com.example.practical14;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity implements
View.OnClickListener{
Button buttonStart, buttonStop,buttonNext;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
buttonStart = findViewById(R.id.buttonStart);
buttonStop = findViewById(R.id.buttonStop);
buttonNext = findViewById(R.id.buttonNext);
buttonStart.setOnClickListener(this);
buttonStop.setOnClickListener(this);
buttonNext.setOnClickListener(this);
}
public void onClick(View src) {
switch (src.getId()) {
case R.id.buttonStart:
startService(new Intent(this, MyService.class));
break;
case R.id.buttonStop:
stopService(new Intent(this, MyService.class));
break;
case R.id.buttonNext:
Intent intent=new Intent(this,NextPage.class);
startActivity(intent);
break;
}
}
}
NextPage.java
//Created by - MONU NNNN
package com.example.practical14;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
public class NextPage extends AppCompatActivity {
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_next);
}
}
activity_next.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<androidx.coordinatorlayout.widget.CoordinatorLayout
xmlns:android="http://schemas.android.com/apk/res/android"
xmlns:app="http://schemas.android.com/apk/res-auto"
xmlns:tools="http://schemas.android.com/tools"
android:layout_width="match_parent"
android:layout_height="match_parent"
tools:context=".NextPage">
<TextView
android:id="@+id/textView"
android:layout_width="wrap_content"
android:layout_height="wrap_content"
android:layout_marginEnd="8dp"
android:layout_marginStart="8dp"
android:layout_marginTop="200dp"
android:text="Next Page"
app:layout_constraintEnd_toEndOf="parent"
app:layout_constraintStart_toStartOf="parent"
app:layout_constraintTop_toTopOf="parent" />
</androidx.coordinatorlayout.widget.CoordinatorLayout>
MyService.java
//Created by - MONU NNNN
package com.example.practical14;
import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.IBinder;
import android.widget.Toast;
import androidx.annotation.Nullable;
public class MyService extends Service {
MediaPlayer myPlayer;
@Nullable
@Override
public IBinder onBind(Intent intent) {
return null;
}
@Override
public void onCreate() {
Toast.makeText(this, "Service Created", Toast.LENGTH_LONG).show();
myPlayer = MediaPlayer.create(this, R.raw.earth);
myPlayer.setLooping(false); // Set looping
}
@Override
public void onStart(Intent intent, int startid) {
Toast.makeText(this, "Service Started", Toast.LENGTH_LONG).show();
myPlayer.start();
}
@Override
public void onDestroy() {
Toast.makeText(this, "Service Stopped", Toast.LENGTH_LONG).show();
myPlayer.stop();
}
}
AndroidManifest.xml
<!--Created by - MONU NNNN -->
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
package="com.example.practical14">
<application
android:allowBackup="true"
android:icon="@mipmap/ic_launcher"
android:label="@string/app_name"
android:roundIcon="@mipmap/ic_launcher_round"
android:supportsRtl="true"
android:theme="@style/Theme.AppCompat.Light">
<activity
android:name=".MainActivity"
android:exported="true">
<intent-filter>
<action android:name="android.intent.action.MAIN" />
<category android:name="android.intent.category.LAUNCHER" />
</intent-filter>
</activity>
<activity android:name=".NextPage"></activity>
<service
android:name=".MyService"
android:enabled="true" />
</application>
</manifest>
 
Question 15 :Create an application to Create, Insert, update, Delete and retrieve operations on the database.
              Solution 15 :
activity_main.xml
 
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:orientation="vertical" >
<EditText
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:hint="Enter id to update or delete"
android:id="@+id/id"
android:onClick="buttonAction"/>
<EditText
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:hint="Enter task to insert or update"
android:id="@+id/task" />
<LinearLayout
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:orientation="vertical">
<Button
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:id="@+id/insert"
android:text="Insert"
android:onClick="buttonAction"/>
<Button
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:id="@+id/view"
android:text="View"
android:onClick="buttonAction" />
<Button
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:text="Update"
android:onClick="buttonAction"
android:id="@+id/update" />
<Button
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:text="Delete"
android:onClick="buttonAction"
android:id="@+id/delete" />
</LinearLayout>
<TextView
android:layout_width="match_parent"
android:layout_height="wrap_content"
android:id="@+id/text"/>
</LinearLayout>
MainActivity.java
//Created by - MONU NNNN
package com.example.practical15;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
public class MainActivity extends Activity {
EditText id,task;
Button insert,view,update,delete;
TextView text;
DatabaseHelper db;
@Override
protected void onCreate(Bundle savedInstanceState) {
super.onCreate(savedInstanceState);
setContentView(R.layout.activity_main);
id=(EditText)findViewById(R.id.id);
task=(EditText)findViewById((R.id.task));
insert=(Button)findViewById(R.id.insert);
view=(Button)findViewById(R.id.view);
update=(Button)findViewById(R.id.update);
delete=(Button)findViewById(R.id.delete);
text=(TextView)findViewById(R.id.text);
db=new DatabaseHelper(getApplicationContext());
}
public void buttonAction(View view){
switch (view.getId()){
case R.id.insert:
db.insertRecord(task.getText().toString());
Toast.makeText(getApplicationContext(),"record
inserted",Toast.LENGTH_LONG).show();
break;
case R.id.view:
text.setText(db.getRecords());
break;
case R.id.update:
db.updateRecord(id.getText().toString(),task.getText().toString());
Toast.makeText(getApplicationContext(),"record
updated",Toast.LENGTH_LONG).show();
break;
case R.id.delete:
db.deleteRecord(id.getText().toString());
Toast.makeText(getApplicationContext(),"record
deleted",Toast.LENGTH_LONG).show();
break;
}
}
}
DatabaseHelper.java
//Created by - MONU NNNN
package com.example.practical15;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
public class DatabaseHelper extends SQLiteOpenHelper{
private static final String DB_NAME="demodb";
private static final int DB_VERSION=1;
private static final String TABLE_NAME="record";
private static final String ID_COL="id";
private static final String TASK_COL="task";
public DatabaseHelper(Context context) {
super(context, DB_NAME, null, DB_VERSION);
}
@Override
public void onCreate(SQLiteDatabase db) {
String query="CREATE TABLE "+TABLE_NAME+" ("+ID_COL+" INTEGER PRIMARY
KEY,"+TASK_COL+" TEXT)";
db.execSQL(query);
}
@Override
public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
// Drop older table if existed
db.execSQL("DROP TABLE IF EXISTS " + TABLE_NAME);
// Create table again
onCreate(db);
}
public void insertRecord(String name){
SQLiteDatabase db=this.getWritableDatabase();
ContentValues values=new ContentValues();
values.put(TASK_COL,name);
db.insert(TABLE_NAME,null,values);
db.close();
}
public String getRecords(){
String query="SELECT * FROM "+TABLE_NAME;
String result="";
SQLiteDatabase db=this.getReadableDatabase();
Cursor cursor=db.rawQuery(query,null);
cursor.moveToFirst();
while(cursor.isAfterLast()==false){
result+=cursor.getString(0)+" "+cursor.getString(1)+"\n";
cursor.moveToNext();
}
db.close();
return result;
}
public void updateRecord(String id,String task){
SQLiteDatabase db=this.getWritableDatabase();
ContentValues values=new ContentValues();
values.put(TASK_COL,task);
db.update(TABLE_NAME,values,"id=?",new String[]{id});
db.close();
}
public void deleteRecord(String id){
SQLiteDatabase db=this.getWritableDatabase();
db.delete(TABLE_NAME,"id=?",new String[]{id});
db.close();
}

