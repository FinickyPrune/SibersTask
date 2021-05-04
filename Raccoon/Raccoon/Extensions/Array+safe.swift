//
//  Array+safe.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation

extension Array {
    
    subscript(safe index: Int) -> Element? {
        guard index >= 0 && index < self.count else {
            return nil
        }
        return self[index]
    }
    
}
