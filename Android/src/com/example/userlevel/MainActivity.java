package com.example.userlevel;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;


public class MainActivity extends Activity {
    
    private Button rotateBtn;
	private Button leftBtn;
	private Button rightBtn;
	private Button downBtn;
	private BluetoothAdapter myBluetoothAdapter;
	private Set<BluetoothDevice> pairedDevices;
	private String direction=null;
	private int i=0,time=0;
	private static UUID generalUuid = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
	private BluetoothSocket socket;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// take an instance of BluetoothAdapter - Bluetooth radio
		myBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
		
		if (myBluetoothAdapter == null) {
			rotateBtn.setEnabled(false);
			leftBtn.setEnabled(false);
			rightBtn.setEnabled(false);
			downBtn.setEnabled(false);
		} else {
			rotateBtn = (Button) findViewById(R.id.rotatebutton);
			rotateBtn.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					direction="11";
					i++;
					try {
						write(direction);
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			});
			leftBtn = (Button) findViewById(R.id.leftbutton);
			leftBtn.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					direction="33";
					i++;
					try {
						write(direction);
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			});
			rightBtn = (Button) findViewById(R.id.rightbutton);
			rightBtn.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					direction="44";
					i++;
					try {
						write(direction);
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			});
			downBtn = (Button) findViewById(R.id.downbutton);
			downBtn.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					direction="22";
					i++;
					try {
						write(direction);
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			});
			if (myBluetoothAdapter.isEnabled()) {
				Intent turnOnIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
				startActivityForResult(turnOnIntent, 1);
				Set<BluetoothDevice> pairedDevices= myBluetoothAdapter.getBondedDevices();

				if (pairedDevices.size() > 0) {					
					//try {
					// Attempt to connect to the device
					for (BluetoothDevice device : pairedDevices) {
			            // Add the name and address to an array adapter to show in a ListView
			            //if(device.getName().equalsIgnoreCase(("player1"))){
			                try {
			                	socket= device.createRfcommSocketToServiceRecord(generalUuid);
			                	socket.connect();
			                } catch (IOException e) {
			                    e.printStackTrace();
			                }
			            //}
			        }
						//BluetoothDevice[] devices = (BluetoothDevice[]) bondedDevices.toArray();
						//BluetoothDevice device = devices[0];
						/*ParcelUuid[] uuids = device.getUuids();
						BluetoothSocket socket = device.createRfcommSocketToServiceRecord(uuids[0].getUuid());
						socket.connect();
						outputStream = socket.getOutputStream();
						inStream = socket.getInputStream();*/
					//} catch (IOException e) {
						// TODO Auto-generated catch block
						//e.printStackTrace();
					//}
				}
			}
		}
	}
	
	public void write(String s) throws IOException {
		if(time==0){
			time=1;
			s=s+i+i;
		}
		else{
			if(i<10){
				s=s+i;
			}
			if(i==10){
				i=0;
				s=s+i;
			}
		}
		socket.getOutputStream().write(s.getBytes());
		
	}



    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}


