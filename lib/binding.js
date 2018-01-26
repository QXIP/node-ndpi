const addon = require('../build/Release/node-ndpi-native');

function NodeNdpi(name) {
    this.greet = function(str) {
        return _addonInstance.greet(str);
    }

    var _addonInstance = new addon.NodeNdpi(name);
}

module.exports = NodeNdpi;
