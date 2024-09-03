function convertToBinNotationArray(uint16Data){
    let ret = "{";
    for(let val of uint16Data){ 
        ret += ("  0b"+("0000000000000000"+val.toString(2)).substr(-16))+",\n"
    }
	ret+="},"
    return ret;
}
function convertToHexNotationArray(uint16Data){
    let ret = "{";
    for(let val of uint16Data){ 
        ret += ("0x"+("0000"+val.toString(16)).substr(-4))+", ";
    }
    ret = ret.substring(0, ret.length-2) + "},";
    return ret;
}
function uint16ArrayToHexNotationArrays(uint16Arrays){
    let ret = "{\n";
    for(let val of uint16Arrays){
		ret += convertToHexNotationArray(val)+"\n";
	}
	ret += "}";
	return ret;
}
function uint8ToHexNotationArray(uint8Data){
    let ret = "{";
    for(let val of uint8Data){ 
        ret += ("0x"+("00"+val.toString(16)).substr(-2))+", ";
    }
    ret = ret.substring(0, ret.length-2) + "},";
    console.log(ret);
}