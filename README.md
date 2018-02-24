# ![image](https://user-images.githubusercontent.com/1423657/36633764-503e637e-199b-11e8-8784-117a04167ce6.png)

NodeJS Native Binding for the [nDPI](https://github.com/ntop/ndpi) Deep Packet Inspection Library

#### Usage
```javascript
const ndpi = require('node-ndpi');
```
###### Initialize
```javascript
ndpi.init();
```
###### Set Callback
```javascript
var myCallback = function(id,p){ console.log(id) };
ndpi.addProtocolHandler(myCallback); 
```
###### Push Packets
```javascript
ndpi.processPacket(header, packet.buf);
``` 
###### Close
```javascript
ndpi.finish();
```

#### Status
* In Development! 
* Testers & Contributors Welcome

###### (C) 2018 QXIP BV, LICENSED UNDER GPLv3


