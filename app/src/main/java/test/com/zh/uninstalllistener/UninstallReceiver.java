package test.com.zh.uninstalllistener;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

/**
 * 创建日期：2019/3/21
 * 描述:
 *
 * @author: zhaoh
 */
public class UninstallReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        Toast.makeText(context,intent.getData()+"包被卸载了",Toast.LENGTH_LONG).show();
    }
}
