package com.cabinet.parcel;

import android.os.Parcelable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.cabinet.parcel.pracel.Parcel;

public class MainActivity extends AppCompatActivity{


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Parcel parcel = new Parcel();

        parcel.writeInt(25);
        parcel.writeInt(66);

        parcel.setDataPosition(0);

        int num1 = parcel.readInt();
        int num2 = parcel.readInt();

        Log.e("TAG", "num1 = " + num1+"  ,  num2 = " + num2 );

    }

}
