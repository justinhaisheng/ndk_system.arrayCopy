package com.aispeech.array.javautil;

/**
 * @创建者 luhaisheng
 * @创建时间 2020/2/22 21:08
 * @描述
 */
public class HashMap<K,V> {
    /*
    *散列桶
    *@author luhaisheng
    *@time 2020/2/22 21:25
    */
    public MapEntry[] table;
    /*
    *存放个数
    *@author luhaisheng
    *@time 2020/2/22 21:26
    */
    transient int size;


    /**
     * 扩容阀值
     */
    int threshold = 8;

    //不允许重复
    public V push(K key,V value){
        if (table == null){
            table = new MapEntry[8];
        }

        if (key == null){//可以  不允许为null
            return null;
        }
        //先hash
        int hash  = hash(key);
        //获取Index
        int index = getIndex(hash,table.length);

        MapEntry<K,V> e = table[index];
        while (e!=null){
            if (e.hash == hash && ( key == e.key) || key.equals(e.key)){
                return e.value;
            }
            e = e.next;//一个桶一个桶的找
        }

        //插入
        addEntry(hash,key,value,index);
        return value;
    }


    public V get(K key){// 如果用数组去实现 复杂度是 O(n)
        if(key == null){
            // 自行看源码
            return null;
        }

        MapEntry<K,V> entry = getEntry(key);
        return entry == null ? null:entry.value;
    }

    private MapEntry<K, V> getEntry(K key) {
        // 1. 找到 table 的位置
        int hash = hash(key);
        int index = getIndex(hash,table.length);

        MapEntry<K,V> e = table[index];
        while (e!=null){
            if (e.hash == hash && ( key == e.key) || key.equals(e.key)){
                return e;
            }
            e = e.next;//一个桶一个桶的找
        }


        return null;
    }

    private void addEntry(int hash,K key,V value,int index){

        if (size >= threshold && table[index]!=null){//判断是否需要扩容
            resize(size << 1);//扩容一倍
            //重新计算index
            index = getIndex(hash,table.length);
        }
        createEntry(hash,key,value,index);
        size++;
    }

    /**
     * 扩容因子 , 也有一些技巧
     */
    final float loadFactor = 0.75f;
    private void resize(int newCapacity){
        MapEntry<K, V>[] newTable = new MapEntry[newCapacity];
        // 直接把之前的数组搬过来 ，行不行？ 扩容之后 index 会变 复杂度 O(n)
        transfrom(newTable);
        table = newTable;
        threshold = (int)(newCapacity * loadFactor);
    }

    /**
     * 重新计算逻动 散列
     * @param newTable
     */
    private void transfrom(HashMap<K, V>.MapEntry<K, V>[] newTable) {
        int newCapacity = newTable.length;

        for(MapEntry<K, V> e: table){
            while(null != e){
                // 从原来的数组中获取数据 Entry , 保证新的数组能链上
                MapEntry<K, V> next = e.next;

                // 重新计算 index
                int index = getIndex(e.hash,newCapacity);
                // 保证新的数组能链上
                e.next = newTable[index];
                newTable[index] = e;

                e = next;
            }
        }
    }
    private void  createEntry(int hash,K key,V value,int index){
        MapEntry<K,V> newMapEntry = new MapEntry<>(hash,key,value,table[index]);
        table[index] = newMapEntry;
    }



    /**
     * 通过 hash 值找到所在的 table 的 index
     * @param hash
     * @return
     */
    private int getIndex(int hash,int length){
        return hash & length -1;
    }


    private int hash(K key) {
        int h = 0;
        //自己的高位和自己的地位进行了异或
        return (key == null) ? 0:( (h = key.hashCode()) ^ ( h>>>16) );
    }


    /*
    *散列桶
    *@author luhaisheng
    *@time 2020/2/22 21:18
    */
    public class MapEntry<K,V>{
        K key;
        V value;
        MapEntry<K,V> next;
        int hash;
        public MapEntry(int hash,K key,V value,MapEntry<K,V> next){
            this.key = key;
            this.value = value;
            this.hash = hash;
            this.next = next;
        }
    }

    public int getSize() {
        // TODO Auto-generated method stub
        return table.length;
    }
}
