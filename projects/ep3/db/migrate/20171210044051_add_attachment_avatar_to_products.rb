class AddAttachmentAvatarToProducts < ActiveRecord::Migration[4.2]
  def self.up
    change_table :products do |t|
      t.attachment :avatar
    end
  end

  def self.down
    remove_attachment :products, :avatar
  end
end
