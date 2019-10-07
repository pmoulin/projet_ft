import iplocate from 'node-iplocate'
import request from 'request-promise'

export default class geolocation {
/**
 * return promise
 */
    async getIp()
    {
        var options = {
            uri: "https://api.ipify.org",
            method: "GET",
            qs: {  // Query string like ?key=value&...
                key : 'null'
            },
            json: true
        }
        try {
            return await request(options);
            
        } catch (err) {
            return null;
        };
    }

    /**
    * return object
    */
    async getPos(ip)
    {
        return await iplocate(ip).then(res => {
            return {lat : res.latitude, lon : res.longitude}
          })
    }

}