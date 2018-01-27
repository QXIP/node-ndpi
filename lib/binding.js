/*  nDPI Node.js Native Binding         */
/*  (c) 2018 QXIP BV, The Netherlands 	*/
/*  http://qxip.net 			        */
/*  See LICENSE for license details     */

const addon = require('../build/Release/node-ndpi-native');

function NodeNdpi(name) {
    
    this.greet = function(str) {
        return _addonInstance.greet(str);
    }
    
    this.init = function() {
        return  _addonInstance.init();  
    }
    
    this.addProtocolHandler = function(callback) {
         return  _addonInstance.addProtocolHandler(callback);  
    }
    
    this.setDatalinkType = function(ref) {
        return  _addonInstance.setDatalinkType(ref);  
    }

    this.processPacket = function(header,packet) {
        return  _addonInstance.processPacket(header,packet);  
    }
    
    this.finish = function() {
        return  _addonInstance.finish();  
    }

    var _addonInstance = new addon.NodeNdpi(name);
}

module.exports = NodeNdpi;
