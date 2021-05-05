//
//  DataManager.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation


class BasicDataManager {
    
    private var integerData: [Int] = []
    
    
    init() {
        
        let defaults = UserDefaults.standard
        if let defaultData = defaults.array(forKey: "IntegerData") as? [Int] {
            integerData = defaultData
        }
        else {
            integerData = (0..<100).map{_ in Int.random(in: 0..<100)}
            defaults.set(integerData, forKey: "IntegerData")
        }
    }
    
}

extension BasicDataManager: DataManager {
 
    func getStringValue(at index: Int) -> String {
        guard let intData = integerData[safe: index] else {
            fatalError("Index out of bounds.")
        }
        return String(intData)
    }
    
    func getDataCount() -> Int{
        return integerData.count
    }
 
    func removeValue(at index: Int) {
        integerData.remove(at: index)
    }
    
    func insertValue(_ value: Int, at index: Int) {
        integerData.insert(value, at: index)
    }
    
    func updateValue(for value: Int, at index: Int) {
        integerData[index] = value
    }
    

}
