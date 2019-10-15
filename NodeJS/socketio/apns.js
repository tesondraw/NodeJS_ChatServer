var apn = require('apn');


var apnProvider = new apn.Provider({  
    token: {
       key: 'apns.p8', // Path to the key p8 file
       keyId: '6UTDUCYG93', // The Key ID of the p8 file (available at https://developer.apple.com/account/ios/certificate/key)
       teamId: '35Y285QLG5', // The Team ID of your Apple Developer Account (available at https://developer.apple.com/account/#/membership/)
   },
   production: false // Set to true if sending a notification to a production iOS app
});

function apns() {

}

apns.send = function(token, content) {
    console.log(token);
    console.log(content);

    // Prepare a new notification
    var notification = new apn.Notification();
    // Specify your iOS app's Bundle ID (accessible within the project editor)
    notification.topic = 'com.chanjoy.SocketIOTest';

    // Set expiration to 1 hour from now (in case device is offline)
    notification.expiry = Math.floor(Date.now() / 1000) + 3600;

    // Set app badge indicator
    notification.badge = 1;

    // Play ping.aiff sound when the notification is received
    notification.sound = 'default';

    // Display the following message (the actual notification text, supports emoji)
    notification.alert = "你的好友给你发来一条消息";//'Hello World \u270C';

    // Send any extra payload data with the notification which will be accessible to your app in didReceiveRemoteNotification
    notification.payload = {content: content};//{id: 123};

    // Actually send the notification
    apnProvider.send(notification, token).then(function(result) {  
        // Check the result for any failed devices
        console.log("推送回调结果：", result);
    });
    
}

module.exports = apns;