function convertToBinNotationArray(uint16Data){
    let ret = "{";
    for(let val of uint16Data){ 
        ret += ("  0b"+("0000000000000000"+val.toString(2)).substr(-16))+",\n"
    }
	ret+="},"
    return ret;
}
function convertToHexNotationArray(intData, intSize){
    let ret = "{";
    let nibbles = "";
    for(let i=0; i<(intSize/4); i++) nibbles += "0";
    for(let val of intData){ 
        ret += ("0x"+(nibbles + val.toString(16)).substr(-intSize/4))+", ";
    }
    ret = ret.substring(0, ret.length-2) + "},";
    return ret;
}
function intArrayToHexNotationArrays(intArrays, intSize){
    let ret = "{\n";
    for(let val of intArrays){
		ret += convertToHexNotationArray(val, intSize)+"\n";
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
function intTransposeArrays(intArrays, intSize){
    let ret = [];
    for(let i=0; i<intArrays.length; i++){
        ret[i] = intTranspose(intArrays[i], intSize);
    }
    return ret;
}