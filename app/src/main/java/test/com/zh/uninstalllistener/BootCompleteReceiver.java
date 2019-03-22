package test.com.zh.uninstalllistener;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;

/**
 * 创建日期：2019/3/21
 * 描述: 开机监听
 *
 * @author: zhaoh
 */
public class BootCompleteReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        Toast.makeText(context,context.getPackageName()+"安装好了",Toast.LENGTH_LONG).show();
        Log.d("BootCompleteReceiver", "开机启动完成");
        myNotify(context);
    }

    /**
     * 发送一个通知
     */
    private void myNotify(Context context) {
        NotificationManager nm = (NotificationManager) context
                .getSystemService(Context.NOTIFICATION_SERVICE);
        PendingIntent pendingIntent = null;
        Intent it = null;
        it = new Intent(context, MainActivity.class);
        pendingIntent = PendingIntent.getActivity(context, 0,
                it, PendingIntent.FLAG_ONE_SHOT);
        Notification baseNF = new Notification.Builder(context)
                .setAutoCancel(true)
                .setContentTitle("开机广播")
                .setContentText("测试开机广播")
                .setTicker("开机广播")
                .setDefaults(
                        Notification.DEFAULT_SOUND
                                | Notification.DEFAULT_VIBRATE)
                .setContentIntent(pendingIntent)
                .setSmallIcon(R.mipmap.ic_launcher)
                .setWhen(System.currentTimeMillis()).build();
        nm.notify(0, baseNF);
    }
}
